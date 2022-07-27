#include<iostream>

using namespace std;

typedef struct node {
	int val;
	node *next = NULL;
	node(int i) : val(i), next(NULL) {}
} node;


void print(node *base) {
	while(base) { cout << base->val << " " ; base = base->next; }
	cout << endl;
}

void recursion(node* previous, node* current, node *next)
{
	if (!current || !next) { 
		cout << current->val << " " <<  endl;
 		return ;
	}

	cout << current->val << " " ;

	while(current->val == next->val) {  
		node *tmp = next;
		next = next->next;
		delete tmp;
	}
	current->next = next;
	current = current->next;
	next = next->next;
	
	recursion(previous, current, next);

}


int main() {
	node *head = new node(1);
	head->next = new node(1);
	head->next->next = new node(3);
	head->next->next->next = new node(4);
	head->next->next->next->next = new node(4);
	head->next->next->next->next->next = new node(6);
	head->next->next->next->next->next->next = new node(6);
	head->next->next->next->next->next->next->next = new node(7);

	node *previous = NULL;
	node *current = head;
	node *next = current->next;

	node *tmp = head;
	print(tmp);

	recursion(previous, current, next);
}
