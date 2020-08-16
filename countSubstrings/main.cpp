#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#define DEBUG_MODE 1
using namespace std;



namespace Suffix {

	struct Node {
		int len = 0;
		map<char, Node*> next;
		Node* link = 0;
		vector<Node*> linking;
		int treeSize = 1;
		bool leaf = false;
	};

	struct Stree {
		vector<Node> data;
		int n;

		Stree(string s) {
			n = s.size();

			data.reserve(2*n+1);
			data.push_back(Node());

			Node* last = &data.back();
			last->len = 0, last->link = 0;

			for(int ind = 0; ind < n; ind++) {
				char c = s[ind];

				data.push_back(Node() );
				Node* prev = last->link, *cur = &data.back();
				cur->len = ind+1;
				last->next[c] = cur;

				while(prev != 0) {
					if(prev->next.count(c))
						break;
					prev->next[c] = cur;
					prev = prev->link;
				}

				if(prev == 0)
					cur->link = &data[0];
				else {
					Node* next = prev->next[c];

					if(next->len == prev->len + 1)
						cur->link = prev->next[c];
					else {
						data.push_back(Node());
						Node* added = &data.back();

						added->len = prev->len+1;
						added->next = next->next;
						added->link = next->link;

						cur->link = added;
						next->link = added;

						while(prev != 0 && prev->next[c] == next) {
							prev->next[c] = added;
							prev = prev->link;
						}
					}
				}

				last = cur;
				last->leaf = true;
			}

			//And now initialize the tree data
			for(int i=data.size()-1;i>0;i--) {
				Node* cur = &data[i], *prev = cur->link;
				prev->linking.push_back(cur);
				prev->treeSize += cur->treeSize;
			}

		}
	};


	struct Addition {
		int val, mult, l, r;
	};

	set<int>* getAdditionsDfs(int n, Node* cur, vector<Addition>& output, vector<set<int> >& boundsContainer) {
		vector<set<int>* > subBounds;
		set<int>* result = 0;

		if(cur->leaf) {
			boundsContainer.push_back(set<int>() );
			subBounds.push_back(&boundsContainer.back());
			result = subBounds.back();
			result->insert(cur->len-1);
		}

		for(Node* next : cur->linking) {
			set<int>* ret = getAdditionsDfs(n, next, output, boundsContainer);
			subBounds.push_back(ret);
			if(result == 0 || result->size() < ret->size())
				result = ret;
		}

		//Otherwise add bounds to largest subset
		for(set<int>* cset : subBounds) if(cset != result) {
			auto csetcur = cset->begin(), csetnext = csetcur;

			do {
				csetnext++;
				int pos = *csetcur;

				int l = 0, r = n;
				set<int>::iterator it = result->lower_bound(pos);

				//Find the correct bounds for the containing segment
				bool inside = true;
				if(it != result->end() )
					r = *it;
				if(it != result->begin() )
					l = *(--it);
				else
					inside = false;

				//Find the right bound of added segment
				int cr = n;
				if(csetnext != cset->end() )
					cr = *csetnext;

				if(inside) {
					if(l+1-cur->len > 0)
						output.push_back({l+1-cur->len, 1, pos, r});
					output.push_back({l+1, -1, pos, r});
				}

				int lb = pos+1-cur->len, rb = pos+1;

				if(cr < r) {
					if(lb > 0) output.push_back({lb, -1, cr, r});
					output.push_back({rb, 1, cr, r});
				}
				else if(r<cr){
					if(lb > 0) output.push_back({lb, 1, r, cr});
					output.push_back({rb, -1, r, cr});
				}

				result->insert(pos);

				csetcur = csetnext;
			}while(csetcur != cset->end() );
		}

		return result;
	}

	vector<Addition> getAdditions(string s) {
		int n = s.size();
		Stree st(s);
		vector<Addition> result;
		vector<set<int> > boundsContainer;
		boundsContainer.reserve(2*n+1);

		getAdditionsDfs(n, &st.data[0], result, boundsContainer);
		//Now add the basic additios
		for(int i=0;i<n;i++)
			result.push_back({i+1, 1, i, n});

		sort(result.begin(), result.end(), [](Addition l, Addition r) {return l.val < r.val;});
		return result;
	}

};




//--------------------------------------------------------------
//Fenwick tree

struct Ftree {
	vector<long long> data;
	int n;

	Ftree(int nsize) {
		n = nsize;
		data.resize(n, 0);
	}

	long long get(int pos) {
		if(pos == 0)
			return 0;
		return data[pos] + get(pos - (pos&-pos));
	}
	void add(int pos, int toAdd) {
		if(pos >= n)
			return;
		data[pos] += toAdd;
		add(pos + (pos&-pos), toAdd);
	}
};




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	string s;
	cin >> s;

	auto additions = Suffix::getAdditions(s);

	vector<Suffix::Addition*> byL, byR;
	for(auto &c : additions) {
		byL.push_back(&c);
		byR.push_back(&c);
	}

	sort(byL.begin(), byL.end(), [](Suffix::Addition* l, Suffix::Addition* r) {return l->l < r->l;} );
	sort(byR.begin(), byR.end(), [](Suffix::Addition* l, Suffix::Addition* r) {return l->r < r->r;} );

	int lind = 0, rind = 0;

	struct Query {
		int l, r;
		long long result;
	};

	vector<Query> queries(q);

	for(int i=0;i<q;i++)
		cin >> queries[i].l >> queries[i].r;

	vector<Query*> qbyR;
	for(auto &c : queries)
		qbyR.push_back(&c);
	sort(qbyR.begin(), qbyR.end(), [](Query* l, Query* r) {return l->r < r->r;} );


	Ftree supto(n+2), cntupto(n+2);

	for(Query* qp : qbyR) {
		while(lind < (int)byL.size() && byL[lind]->l <= qp->r) {
			auto lit = byL[lind];
			supto.add(lit->val+1, lit->val * lit->mult);
			cntupto.add(lit->val+1, lit->mult);
			lind++;
		}

		while(rind < (int)byR.size() && byR[rind]->r <= qp->r) {
			auto rit = byR[rind];
			supto.add(rit->val+1, -rit->val * rit->mult);
			cntupto.add(rit->val+1, -rit->mult);
			rind++;
		}

		//And actually answer the query
		qp->result = supto.get(n+1) - supto.get(qp->l) - qp->l * (cntupto.get(n+1) - cntupto.get(qp->l) );
	}

	for(auto &c : queries)
		cout << c.result << '\n';


	return 0;
}
