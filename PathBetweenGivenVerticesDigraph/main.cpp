#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Data structure to store graph edges
struct Edge {
    int src, dest;
};

// Class to represent a graph object
class Graph
{
public:
    // construct a vector of vectors to represent adjacency list in C++
    vector<vector<int>> adjList;

    // Graph Constructor
    Graph(const vector<Edge> &edges, int N)
    {
        // resize the vector to N elements each of type vector<int>
        adjList.resize(N);

        // add edges to the directed graph
        for (auto &edge: edges) {
            adjList[edge.src].push_back(edge.dest);
        }
    }
};

// Function to perform BFS traversal from the source vertex in the graph to
// determine if the destination vertex is reachable from the source or not
bool isConnected(const Graph &graph, int src, int dest,
                vector<bool> &discovered)
{
    // create a queue used to do BFS
    queue<int> q;

    // mark source vertex as discovered
    discovered[src] = true;

    // push source vertex into the queue
    q.push(src);

    // run till queue is not empty
    while (!q.empty())
    {
        // pop front node from queue and print it
        int v = q.front();
        q.pop();

        // if destination vertex is found
        if (v == dest) {
            return true;
        }

        // do for every edge (v -> u)
        for (int u : graph.adjList[v])
        {
            if (!discovered[u])
            {
                // mark it discovered and push it into queue
                discovered[u] = true;
                q.push(u);
            }
        }
    }

    return false;
}

int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges = {
        {0, 3}, {1, 0}, {1, 2}, {1, 4}, {2, 7}, {3, 4},
        {3, 5}, {4, 3}, {4, 6}, {5, 6}, {6, 7}
    };

    // Number of nodes in the graph (labelled from 0 to N-1)
    int N = 8;

    // create a graph from given edges
    Graph graph(edges, N);

    // stores vertex is discovered or not
    vector<bool> discovered(N);

    // source and destination vertex
    int src = 0, dest = 7;

    // perform BFS traversal from the source vertex to check the connectivity
    if (isConnected(graph, src, dest, discovered)) {
        cout << "Path exists from vertex " << src << " to vertex " << dest;
    }
    else {
        cout << "No path exists between vertices " << src << " and " << dest;
    }

    return 0;
}
