#include <iostream>

using namespace std;

struct Object
{
};

template <typename G>
class DFS//generic DFS
{
protected://local types
    typedef typename G::Vertex Vertex;//vertex position
    typedef typename G::Edge Edge;//edge position

    typedef typename G::VertexList VertexList;//vertex position
    typedef typename G::EdgeList EdgeList;//edge position

    typedef typename VertexList::Iterator VertexItor;//vertex position
    typedef typename EdgeList::Iterator EdgeItor;//edge position
// . . .insert other typename shortcuts here
protected:// member data
    const G& graph;// the graph
    Vertex start;// start vertex
    Object *yes, *no;// decorator values
protected:// member functions
    DFS(const G& g);// constructor
    void initialize();// initialize a new DFS
    void dfsTraversal(const Vertex& v);// recursive DFS utility
// overridden functions
    virtual void startVisit(const Vertex& v) {}// arrived at v
    virtual void traverseDiscovery(const Edge& e, const Vertex& from) {}// discovery edge e

    virtual void traverseBack(const Edge& e, const Vertex& from) {}// back edge e
    virtual void finishVisit(const Vertex& v) {}// finished with v
    virtual bool isDone() const// finished?
    {
        return false;
    }

// . . .insert marking utilities here
protected:// marking utilities
    void visit(const Vertex& v)
    {
        v.set("visited", yes);
    }
    void visit(const Edge& e)
    {
        e.set("visited", yes);
    }
    void unvisit(const Vertex& v)
    {
        v.set("visited", no);
    }
    void unvisit(const Edge& e)
    {
        e.set("visited", no);
    }
    bool isVisited(const Vertex& v)
    {
        return v.get("visited") == yes;
    }
    bool isVisited(const Edge& e)
    {
        return e.get("visited") == yes;
    }
};



template <typename G>// constructor
DFS<G>::DFS(const G& g)
    : graph(g), yes(new Object), no(new Object) {}


template <typename G>// initialize  a new DFS
void DFS<G>::initialize()
{
    VertexList verts = graph.vertices();
    for (VertexItor pv = verts.begin(); pv != verts.end(); ++pv)
        unvisit(*pv);// mark vertices unvisited
    EdgeList edges = graph.edges();
    for (EdgeItor pe = edges.begin(); pe != edges.end(); ++pe)
        unvisit(*pe);// mark edges unvisited
}



template <typename G>// recursive traversal
void DFS<G>::dfsTraversal(const Vertex& v)
{
    startVisit(v);// visit v and mark visited
    visit(v);
    EdgeList incident = v.incidentEdges();
    EdgeItor pe = incident.begin();
    while (!isDone() && pe != incident.end())// visit v’s incident edges
    {
        Edge e = *pe++;
        if (!isVisited(e))//discovery edge?
        {
            visit(e);//mark it visited
            Vertex w = e.opposite(v);//get opposing vertex
            if (!isVisited(w))//unexplored?
            {
                traverseDiscovery(e, v);//let’s discover it
                if (!isDone())//continue traversal
                    dfsTraversal(w);
            }
            else
                traverseBack(e, v);// process back edge
        }
    }
    if (!isDone())// finished with v
        finishVisit(v);
}


template <typename G>
class Components : public DFS<G>// count components
{
private:
    int nComponents;// num of components
public:
    Components(const G& g): DFS<G>(g) {}// constructor
    int operator()();// count components

};

template <typename G>
int Components<G>::operator()()// count components
{
    this->initialize();// initialize DFS
    nComponents = 0;// init vertex count
    typename DFS<G>::VertexList verts = this.graph.vertices();
    for (typename DFS<G>::VertexItor pv = verts.begin(); pv != verts.end(); ++pv)
    {
        if (!isVisited(*pv))
        {
            // not yet visited?
            dfsTraversal(*pv);// visit
            nComponents++;// one more component
        }
    }
    return nComponents;
}


template <typename G>
class FindPath : public DFS<G>//find a path by DFS
{
private://local data
    typedef typename DFS<G>::VertexList VertexList;
    typedef typename DFS<G>::Vertex Vertex;
    VertexList path;//the path
    Vertex target;//the target vertex
    bool done;//is target found?
protected:// overridden functions
    void startVisit(const Vertex& v);//visit vertex
    void finishVisit(const Vertex& v);//finished with vertex
    bool isDone() const;//done yet?
public:
    FindPath(const G& g) : DFS<G>(g) {}// constructor
    VertexList operator()(const Vertex& s, const Vertex& t);// find path from s to t
};


template <typename G>// find path from s to t
typename FindPath<G>::VertexList FindPath<G>::operator()(const Vertex& s, const Vertex& t)
{
    this->initialize();// initialize DFS
    path.clear();// clear the path
    target = t;// save the target
    done = false;// traverse starting at s
    dfsTraversal(s);
    return path;// return the path
}


template <typename G>
void FindPath<G>::startVisit(const Vertex& v)// visit vertex
{
    path.push_back(v);// insert into path
    if (v == target)// reached target vertex
        done = true;
}


template <typename G>
void FindPath<G>::finishVisit(const Vertex& v)// finished with vertex
{
    if (!done)// remove last vertex
        path.pop_back();
}

template <typename G>
bool FindPath<G>::isDone() const// done yet?
{
    return done;
}


template <typename G>
class FindCycle : public DFS<G>
{
private:// local data
    typedef typename DFS<G>::EdgeList EdgeList;
    typedef typename EdgeList::Iterator EdgeItor;
    typedef typename DFS<G>::Vertex Vertex;
    typedef typename DFS<G>::Edge Edge;
    EdgeList cycle;// cycle storage
    Vertex cycleStart;// start of cycle
    bool done;// cycle detected?
protected:// overridden functions
    void traverseDiscovery(const Edge& e, const Vertex& from);
    void traverseBack(const Edge& e, const Vertex& from);
    void finishVisit(const Vertex& v);// finished with vertex
    bool isDone() const;// done yet?
public:
    FindCycle(const G& g) : DFS<G>(g) {}// constructor
    EdgeList operator()(const Vertex& s);// find a cycle
};


template <typename G>// find a cycle
typename FindCycle<G>::EdgeList FindCycle<G>::operator()(const Vertex& s)
{
    this->initialize();// initialize DFS
    cycle = EdgeList();
    done = false;// initialize members
    dfsTraversal(s);// do the search
    if (!cycle.empty() && s != cycleStart)
    {
        // found a cycle?
        EdgeItor pe = cycle.begin();
        while (pe != cycle.end())
        {
            // search for prefix
            if ((pe++)->isIncidentOn(cycleStart))
                break; // last edge of prefix?
        }
        cycle.erase(cycle.begin(), pe);// remove prefix
    }
    return cycle;// return the cycle
}



template <typename G>// discovery edge e
void FindCycle<G>::traverseDiscovery(const Edge& e, const Vertex& from)// add edge to list
{
    if (!done)
        cycle.push_back(e);
}




template <typename G>// back edge e
void FindCycle<G>::traverseBack(const Edge& e, const Vertex& from)
{
    if (!done)  // no cycle yet?
    {
        done = true;// cycle now detected
        cycle.push_back(e);// insert final edge
        cycleStart = e.opposite(from);// save starting vertex
    }
}




template <typename G>// finished with vertex
void FindCycle<G>::finishVisit(const Vertex& v)
{
    if (!cycle.empty() && !done)// not building a cycle?
        cycle.pop_back();// remove this edge
}



template <typename G>
bool FindCycle<G>::isDone() const// done yet?
{
    return done;
}

int main()
{
    //Components components(G);// declare a Components object
    // int nc = components();// compute the number of components


    cout << "Hello world!" << endl;
    return 0;
}
