/**Given a weighted digraph (Directed), find the least cost path from given source to destination
that have exactly m edges
**/
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

// data structure to store graph edges
struct Edge {
    int src, dest, weight;
};

// class to represent a graph object
class Graph
{
public:
    // construct a vector of vectors to represent  adjacency list
    vector<vector<Edge>> adjList;

    // Graph Constructor
    Graph(const vector<Edge> &edges, int N)
    {
        // resize the vector to N elements of type vector<Edge>
        adjList.resize(N);

        // add edges to the directed graph
        for (auto &edge: edges) {
            adjList[edge.src].push_back(edge);
        }
    }
};

// BFS Node
struct Node {
    int vertex, depth, weight;
};

// Perform BFS on graph g starting from vertex v
int modifiedBFS(Graph const &g, int src, int dest, int m)
{
    // create a queue used to do BFS
    queue<Node> q;

    // push source vertex into the queue
    q.push({src, 0, 0});

    // stores least-cost from source to destination
    int minCost = INT_MAX;

    // run till queue is not empty
    while (!q.empty())
    {
        // pop front node from queue
        Node node = q.front();
        q.pop();

        int v = node.vertex;
        int depth = node.depth;
        int cost = node.weight;

        // if destination is reached and BFS depth is equal to m
        // update minimum cost calculated so far
        if (v == dest && depth == m)
            minCost = min(minCost, cost);

        // don't consider nodes having BFS depth more than m.
        // This check will result in optimized code and also
        // handle cycles in the graph (else loop will never break)
        if (depth > m)
            break;

        // do for every adjacent edge of v
        for (Edge edge : g.adjList[v])
        {
            // push every vertex (discovered or undiscovered) into
            // the queue with depth as +1 of parent and cost equal
            // to cost of parent plus weight of current edge
            q.push( {edge.dest, depth + 1, cost + edge.weight} );
        }
    }

    // return least-cost
    return minCost;
}

int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges =
    {
        {0, 6, -1}, {0, 1, 5}, {1, 6, 3}, {1, 5, 5}, {1, 2, 7},
        {2, 3, 8}, {3, 4, 10}, {5, 2, -1}, {5, 3, 9}, {5, 4, 1},
        {6, 5, 2}, {7, 6, 9}, {7, 1, 6}
    };

    // Number of vertices in the graph
    int N = 8;

    // create a graph from edges
    Graph g(edges, N);

    int src = 0, dest = 3, m = 4;

    // Do modified BFS traversal from source vertex src
    cout << modifiedBFS(g, src, dest, m);

    return 0;
}
