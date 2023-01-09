// dfs - inorder for a graph, depth first search(traversal)...

// source http://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/

#include<iostream>
#include<list>
using namespace std;

class Graph{
	int noOfNodes;
	list<int> *adj;
  public:
	Graph(int n) {
		noOfNodes = n;
		adj = new list<int>[n];
	}

	void addEdge(int s, int d) {
		adj[s].push_back(d);
	}

	void DFS(int node) {
		bool* isTracked = new bool[noOfNodes];
		for(int i =0; i < noOfNodes; ++i) isTracked[i] = false;

		DFSUtils(node, isTracked);
	}

	void DFSUtils(int node, bool* isTracked) {
		if(!isTracked[node]) { // this for checking if the same node exit multiple times, should not exclude ...
		isTracked[node] = true;
		cout << node << " "; }

		for(list<int>::iterator itr = adj[node].begin(); itr != adj[node].end(); ++itr) {
			if(!isTracked[*itr]) DFSUtils(*itr, isTracked);
		}
	}

	void DFS_disconnected_graph() {
		bool* isTracked = new bool[noOfNodes];
		for(int i = 0; i < noOfNodes; ++i) isTracked[i] = false;
		cout << endl << "For disconnected graphs.." << endl;
		int count=0;
		for(int i = 0; i < 4; ++i) 
			if(!isTracked[i]) { DFSUtils(i, isTracked); count++; }
		cout << endl;
		cout << "no of disconnexted ... " << count << endl;
	}
};

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    //g.DFS(2);
    g.DFS_disconnected_graph(); // this is for diconnceted graphs...
}
