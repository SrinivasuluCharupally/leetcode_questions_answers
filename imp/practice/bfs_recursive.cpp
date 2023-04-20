#include<iostream>
#include<list>
#include<vector>
#include<queue>

using namespace std;

class bfs {
	int nodes;
	list<int> *adj;
	bool *isTracked;
	bool *isTracked_rec;

  public:
	bfs(int n) : nodes(n) {
		adj = new list<int>[n];
		isTracked = new bool[n] {false};
		isTracked_rec = new bool[n] {false};


	}

  	void insert(int s, int d) {
		adj[s].push_back(d);
	}

	void BFS (int s) {
		static queue<int> q;
		q.push(s);
	  while(!q.empty()) {
		if(!isTracked[q.front()]) {
			isTracked[q.front()] = true;
			cout << q.front() << " " <<endl;
		}

		for(list<int>::iterator itr = adj[q.front()].begin(); itr != adj[q.front()].end(); ++itr) {
			if(!isTracked[*itr]) {
				q.push(*itr);
				isTracked[*itr] == true;
			}
		}

		q.pop();
	   }
	}
	void BFS_recursion (int s) {
		if(!isTracked_rec[s]) {
			isTracked_rec[s] = true;
			cout << s << " " <<endl;
		}

		for(list<int>::iterator itr = adj[s].begin(); itr != adj[s].end(); ++itr) {
			if(!isTracked_rec[*itr]) {
				isTracked_rec[*itr] == true;
				BFS_recursion(*itr);
			}
		}

	}

};

int main() { 

	bfs bfsgraph(4);
	
	bfsgraph.insert(0,1);
	bfsgraph.insert(0,2);
	bfsgraph.insert(1,2);
	bfsgraph.insert(2,0);
	bfsgraph.insert(2,3);
	bfsgraph.insert(3,3);

	cout << "Without recursion" << endl;
	bfsgraph.BFS(2);

	cout << "With recursion" << endl;
	bfsgraph.BFS_recursion(2);
	return 0;
}

