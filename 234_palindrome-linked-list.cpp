#include<iostream>
#include<vector>

using namespace std;


typedef struct node {
	int val;
	node *next;
	node(int i) : val(i), next(NULL) {}
} node;


void recursion(node *head, node *end, vector<int> &cache) {
	if(end->next  == NULL) {
		while(!cache.empty()) {
			if(head->val != cache[cache.size()-1] ) {
				cout << "Not a Palindrom" << endl;
				return;
			}
			head = head->next;
			cache.pop_back();
		}
	}

	cache.push_back(head->val);
//	head = head->next;
//	end = end->next->next;
	return recursion(head->next, end->next->next, cache);
}

int main() {
	node *n = new node(1);
	n->next = new node(2);
	n->next->next = new node(5);
	n->next->next->next = new node(2);
	n->next->next->next->next = new node(2);

	vector<int> cache;
	recursion(n, n, cache);
}
