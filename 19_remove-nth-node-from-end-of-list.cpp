#include<iostream>

using namespace std;

typedef struct node {
	int val;
	node *next = NULL;
	node(int i) : val(i), next(NULL) {}
} node;



void recursion(node *node1, node *base, int nthNodefromend, int &counter) {
	if(node1->next == NULL ) { 
		base->val = base->next->val; 
		base->next = base->next->next;
		return;}
	if(counter >= nthNodefromend)  { base = base->next; node1 = node1->next; }
	else {node1 = node1->next;}

	counter += 1;
	recursion(node1, base, nthNodefromend, counter);

}


int main() {
	node *head = new node(1);
	head->next = new node(2);
	head->next->next = new node(3);
	head->next->next->next = new node(4);
	head->next->next->next->next = new node(5);

	int nthNodefromend = 2, counter=1;
	node *base=head, *offset=NULL;
	recursion(head, base, nthNodefromend, counter);

	while(head) { cout << head->val << " " ; head = head->next; }
	cout << endl;
}
