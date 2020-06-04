#include <iostream>
#include <vector>
using namespace std;

// data structure to store graph edges
struct Edge {
    int src, dest;
};

// class to represent a graph object
class Graph
{
public:
    // construct a vector of vectors to represent adjacency list in C++
    vector<vector<int>> adjList;

    // Graph Constructor
    Graph(const vector<Edge> &edges, int N)
    {
        // resize the vector to N elements of type vector<int>
        adjList.resize(N);

        // add edges to the directed graph
        for (auto &edge: edges) {
            adjList[edge.src].push_back(edge.dest);
        }
    }
};

// Function to perform DFS traversal in a directed graph to find the
// complete path between source and destination vertices
bool isConnected(const Graph &graph, int src, int dest,
        vector<bool> &discovered, vector<int> &path)
{
    // mark current node as discovered
    discovered[src] = true;

    // include current node in the path
    path.push_back(src);

    // if destination vertex is found
    if (src == dest) {
        return true;
    }

    // do for every edge (src -> i)
    for (int i: graph.adjList[src])
    {
        // u is not discovered
        if (!discovered[i])
        {
            // return true if destination is found
            if (isConnected(graph, i, dest, discovered, path))
                return true;
        }
    }

    // backtrack: remove current node from the path
    path.pop_back();

    // return false if destination vertex is not reachable from src
    return false;
}

// Utility function to print a vector
void printPath(const vector<int> &path)
{
    for (int i: path)
        cout << i << ' ';
    cout << endl;
}


// Function to perform DFS traversal in a directed graph  to find the
// complete path between source and destination vertices
void printAllPaths(const Graph &graph, int src, int dest,
		vector<bool> &discovered, vector<int> &path)
{
	// mark current node as discovered
	discovered[src] = true;

	// include current node in the path
	path.push_back(src);

	// print the complete path if destination vertex is found
	if (src == dest) {
		printPath(path);
	}

	// do for every edge (src -> i)
	for (int i: graph.adjList[src])
	{
		// proceed if u is not discovered
		if (!discovered[i]) {
			printAllPaths(graph, i, dest, discovered, path);
		}
	}

	// backtrack: remove current node from the path & mark it as not discovered
	path.pop_back();
	discovered[src] = false;
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

    // vector to store the complete path between source and destination
    vector<int> path;

    // perform DFS traversal from the source vertex to check the connectivity
    // and store path from the source vertex to the destination vertex
    if (isConnected(graph, src, dest, discovered, path))
    {
        cout << "Path exists from vertex " << src << " to vertex " << dest;
        cout << "\nThe complete path is: "; printPath(path);
    }
    else {
        cout << "No path exists between vertices " << src << " and " << dest;
    }

    	// perform DFS traversal from the source vertex to check the connectivity
	// and print all paths from the source vertex to the destination vertex
	printAllPaths(graph, src, dest, discovered, path);

    return 0;
}
