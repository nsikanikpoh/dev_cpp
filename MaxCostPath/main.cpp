#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

// data structure to store graph edges
struct Edge
{
    int src, dest, weight;
};

// class to represent a graph object
class Graph
{
public:
    // construct a vector of vectors of Edge to represent an adjacency list
    vector<vector<Edge>> adjList;

    // Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // resize the vector to N elements of type vector<Edge>
        adjList.resize(N);

        // add edges to the directed graph
        for (auto &edge: edges)
        {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;

            adjList[src].push_back({src, dest, weight});
            adjList[dest].push_back({dest, src, weight});
        }
    }
};

// BFS Node
struct Node
{
    // current vertex number and cost of current path
    int vertex, weight;

    // set of nodes visited so far in current path
    set<int> s;

    // maintain a parent node for printing final path
    Node *parent;
};

// Perform BFS on graph g starting from vertex v
Node* modifiedBFS(Graph const &g, int src, int k)
{
    // create a queue used to do BFS
    queue<Node*> q;

    // stores maximum-cost path information
    Node* maxCostPathLastNode = new Node;

    // add source vertex to set and push it into the queue
    set<int> vertices;
    vertices.insert(0);

    maxCostPathLastNode->s = vertices;
    maxCostPathLastNode->vertex = src;
    maxCostPathLastNode->weight = 0;
    maxCostPathLastNode->parent = nullptr;
    q.push(maxCostPathLastNode);

    // stores front node of queue
    Node* front;


    // run till queue is not empty
    while (!q.empty())
    {
        // pop front node from queue
        front = q.front();
        q.pop();

        int v = front->vertex;
        int cost = front->weight;
        vertices = front->s;

        // if destination is reached and BFS depth is equal to m
        // update minimum cost calculated so far
        if (cost > k && (maxCostPathLastNode == nullptr || maxCostPathLastNode->weight < cost))
            maxCostPathLastNode = front;

        // do for every adjacent edge of v
        for (Edge edge : g.adjList[v])
        {
            // check for cycle
            if (vertices.find(edge.dest) == vertices.end())
            {
                // add current node into the path
                set<int> s = vertices;
                s.insert(edge.dest);

                // stores maximum-cost path information
                Node* newNode = new Node;

                newNode->s = s;
                newNode->vertex = edge.dest;
                newNode->weight = cost + edge.weight;
                newNode->parent = front;

                // push every vertex (discovered or undiscovered) into
                // the queue with cost equal to (cost of parent + weight
                // of current edge)
                q.push(newNode);
            }
        }
    }

    // return max-cost
    return maxCostPathLastNode;
}

void printPath(Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    printPath(node->parent);
    cout << node->vertex << "-";
}

int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges =
    {
        {0, 6, 11}, {0, 1, 5}, {1, 6, 3}, {1, 5, 5}, {1, 2, 7},
        {2, 3, -8}, {3, 4, 10}, {5, 2, -1}, {5, 3, 9}, {5, 4, 1},
        {6, 5, 2}, {7, 6, 9}, {7, 1, 6}
    };

    // Number of nodes in the graph
    int N = 9;

    // create a graph from edges
    Graph g(edges, N);

    int src = 0;
    int cost = 50;

    // Do modified BFS traversal from source vertex src
    Node* maxCostPathLastNode = modifiedBFS(g, src, cost);

    if (maxCostPathLastNode != nullptr)
    {
        cout << "Maximum cost is: " << maxCostPathLastNode->weight << '\n';
        cout << "Maximum cost path is: ";
        printPath(maxCostPathLastNode);
        cout << endl;
    }

    else
        cout << "All paths from source have their costs < " << cost << endl;

    return 0;
}
