#include <iostream>

using namespace std;


//Code Fragment 13.1: The DFS algorithm.
Algorithm DFS(G, v):
    Input: A graph G and a vertex v of G
    Output: A labeling of the edges in the connected component of v as discovery edges and back edges
    label v as visited
    for all edges e in v.incidentEdges() do
        if edge e is unvisited then
            w ← e.opposite(v)
            if vertex w is unexplored then
                label e as a discovery edge
                recursively call DFS(G, w)
            else
                label e as a back edge


//Code Fragment 13.3: DFS on a graph with decorable edges and vertices.

Algorithm DFS(G, v):
    Input: A graph G with decorable vertices and edges, a vertex v of G, such that
        all vertices and edges have been decorated with the status value of unvisited
    Output: A decoration of the vertices of the connected component of v with the
        value visited and of the edges in the connected component of v with values
        discovery and back, according to a depth-first search traversal of G
    v.set("status", visited)
    for all edges e in v.incidentEdges() do
        if e.get("status") = unvisited then
            w ← e.opposite(v)
            if w.get("status") = unvisited then
                e.set("status", discovered)
                DFS(G, w)
        else
            e.set("status", back)




Algorithm BFS(s):
    initialize collection L 0 to contain vertex s
    i ← 0
    while L i is not empty do
        create collection L i+1 to initially be empty
        for all vertices v in L i do
            for all edges e in v.incidentEdges() do
                if edge e is unexplored then
                    w ← e.opposite(v)
                    if vertex w is unexplored then
                        label e as a discovery edge
                        insert w into L i+1
                    else
                        label e as a cross edge
            i ← i + 1
//Code Fragment 13.20: The BFS algorithm.


Algorithm DirectedDFS(v):
    Mark vertex v as visited.
    for each outgoing edge (v, w) of v do
        if vertex w has not been visited then
            Recursively call DirectedDFS(w).
//Code Fragment 13.21: The DirectedDFS algorithm.





Algorithm FloydWarshall(G):
    Input: A digraph G with n vertices
    Output: The transitive closure G ∗ of G
    let v 1 , v 2 , . . . , v n be an arbitrary numbering of the vertices of G
    G 0 ← G
    for k ← 1 to n do
        G k ← G k−1
        for all i, j in {1, . . . , n} with i 6 = j and i, j 6 = k do
            if both edges (v i , v k ) and (v k , v j ) are in G k−1 then
                add edge (v i , v j ) to G k (if it is not already present)
        return G n

//Code Fragment 13.22: Pseudo-code for the Floyd-Warshall algorithm. This algo-
//rithm computes the transitive closure G ∗ of G by incrementally computing a series
//of digraphs G 0 , G 1 , . . . , G n , where k = 1, . . . , n.




Algorithm TopologicalSort(G):
    Input: A digraph G with n vertices
    Output: A topological ordering v 1 , . . . , v n of G
    S ← an initially empty stack.
    for all u in G.vertices() do
        Let incounter(u) be the in-degree of u.
        if incounter(u) = 0 then
            S.push(u)
    i ← 1
    while !S.empty() do
        u ← S.pop()
        Let u be vertex number i in the topological ordering.
        i ← i + 1
        for all outgoing edges (u, w) of u do
            incounter(w) ← incounter(w) − 1
            if incounter(w) = 0 then
                S.push(w)
//Code Fragment 13.23: Pseudo-code for the topological sorting algorithm. (We show
//an example application of this algorithm in Figure 13.12.)



Algorithm ShortestPath(G, v):
    Input: A simple undirected weighted graph G with nonnegative edge weights
        and a distinguished vertex v of G
    Output: A label D[u], for each vertex u of G, such that D[u] is the length of a
        shortest path from v to u in G
    Initialize D[v] ← 0 and D[u] ← +∞ for each vertex u 6 = v.
    Let a priority queue Q contain all the vertices of G using the D labels as keys.
    while Q is not empty do
        {pull a new vertex u into the cloud}
        u ← Q.removeMin()
        for each vertex z adjacent to u such that z is in Q do
            {perform the relaxation procedure on edge (u, z)}
            if D[u] + w((u, z)) < D[z] then
                D[z] ← D[u] + w((u, z))
                Change to D[z] the key of vertex z in Q.
        return the label D[u] of each vertex u
//Code Fragment 13.24: Dijkstra’s algorithm for the single-source, shortest-path
//problem.




Algorithm Kruskal(G):
    Input: A simple connected weighted graph G with n vertices and m edges
    Output: A minimum spanning tree T for G
    for each vertex v in G do
        Define an elementary cluster C(v) ← {v}.
    Initialize a priority queue Q to contain all edges in G, using the weights as keys.
    T ←∅
    {T will ultimately contain the edges of the MST}
    while T has fewer than n − 1 edges do
        (u, v) ← Q.removeMin()
        Let C(v) be the cluster containing v, and let C(u) be the cluster containing u.
        if C(v) 6 = C(u) then
            Add edge (v, u) to T .
            Merge C(v) and C(u) into one cluster, that is, union C(v) and C(u).
        return tree T
//Code Fragment 13.25: Kruskal’s algorithm for the MST problem.



Algorithm PrimJarnik(G):
    Input: A weighted connected graph G with n vertices and m edges
    Output: A minimum spanning tree T for G
    Pick any vertex v of G
    D[v] ← 0
    for each vertex u 6 = v do
        D[u] ← +∞
    Initialize T ← ∅.
    Initialize a priority queue Q with an entry ((u, null), D[u]) for each vertex u,
    where (u, null) is the element and D[u]) is the key.
    while Q is not empty do
        (u, e) ← Q.removeMin()
        Add vertex u and edge e to T .
        for each vertex z adjacent to u such that z is in Q do
            {perform the relaxation procedure on edge (u, z)}
            if w((u, z)) < D[z] then
                D[z] ← w((u, z))
                Change to (z, (u, z)) the element of vertex z in Q.
                Change to D[z] the key of vertex z in Q.
    return the tree T
//Code Fragment 13.26: The Prim-Jarnı́k algorithm for the MST problem.



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
