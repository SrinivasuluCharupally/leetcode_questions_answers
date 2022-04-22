#include<iostream>

using namespace std;

typedef struct node {
	int val;
	node *next = NULL;
	node(int i) : val(i), next(NULL) {}
} node;



void recursion_values(node *node1) {
	if ( node1 == NULL) return;

	if(node1->next != NULL) {
	int first  = node1->val;
	node1->val = node1->next->val;
	node1->next->val = first;
	}

	recursion_values(node1->next->next);

}

void recursion_nodes(node *node1, node* previous) {
	if (node1 == NULL) return;

	node *base = node1->next;
	node *link = node1->next->next;

	if(node1->next != NULL) {
	node *firstnode  = node1;
	node *secondnode = node1->next;
	secondnode->next = firstnode;
	firstnode->next = link;
	
	}
	if(previous != NULL) previous->next = base;

	recursion_nodes(base->next->next, base->next);

}


int main() {
	node *head = new node(1);
	head->next = new node(2);
	head->next->next = new node(3);
	head->next->next->next = new node(4);

	node *base_values = head, *base_nodes = head, *previous = NULL, *print_values=head, *print_nodes = head->next;

	while(head) { cout << head->val << " " ; head = head->next; }
	cout << endl;

	recursion_values(base_values);
	while(print_values) { cout << print_values->val << " " ; print_values = print_values->next; }
	cout << endl;


	recursion_nodes(base_nodes, previous);
	while(print_nodes) { cout << print_nodes->val << " " ; print_nodes = print_nodes->next; }
	cout << endl;
}
