#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
   bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
      multiset <int> m_set;
      int len = nums.size();
      for(int i = 0; i< len; i++){
         multiset <int> :: iterator x = m_set.lower_bound(nums[i]);
         if(x != m_set.end() && *x <= nums[i] + t ) return true;
            if(x != m_set.begin()){
               x = std::next(x, -1);
               if(*x + t >= nums[i])return true;
            }
            m_set.insert(nums[i]);
            if(i >= k){
               m_set.erase(nums[i - k]);
            }
         }
         return false;
      }
};
main(){
   Solution ob;
   vector<int> v = {1,2,3,1};
   cout << (ob.containsNearbyAlmostDuplicate(v, 3,0));
}
