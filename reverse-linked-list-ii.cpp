// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.


#include<iostream>

using namespace std;


typedef struct node {
	int val;
	node *next;
	node(int i) : val(i), next(NULL) { }
} node;

node *tmp = NULL, *startNode = NULL;

void recursion(node *previous, node *currentprevious, node *current, int mystart, int myend) {
	if(current == NULL) return;

	if(current->val > mystart && current->val <= myend) {
		node *tmp = previous->next; // 2
		node *nextcurrent = current->next; // 4
		previous->next = current; // 1->3
		current->next = tmp; // 3->2
		
		currentprevious->next = nextcurrent;
		current = nextcurrent;

	}

	else if(current->val == mystart) {
	        currentprevious = current;	
		current = current->next;
	}
	else {
		

		previous = current;

		current = current->next;
	}

	recursion(previous, currentprevious, current, mystart, myend);

}

int main() {

        node *n = new node(1);
        n->next = new node(2);
        n->next->next = new node(3);
        n->next->next->next = new node(4);
        n->next->next->next->next = new node(5);

        n->next->next->next->next->next = new node(8);
        n->next->next->next->next->next->next = new node(9);

	node *previous = NULL;
	node *currentprevious = NULL;
	node *current = n;

	recursion(previous, currentprevious, current, 2, 4);

	while(n) {
		cout << n->val << endl;
		n = n->next;
	}
}
