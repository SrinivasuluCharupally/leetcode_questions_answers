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
node *base = NULL;

void recursion(node* previous, node* current, node *next)
{
    // base case
	if (!current || !next) { 
		previous->next = current;
		print(base);
 		return ;
	}

	bool dub = false;
	while(current->val == next->val) {  
		next = next->next;
		delete current->next;
		current->next = next;
		dub = true;
	}
	if(dub == false) { 
		if(previous == NULL) { previous = current; base = previous; }
		else { previous->next = current;}

		current = next;
		next = next->next;
	
	}
	
	else {
		delete current;
		current = next;
		next = next->next;
	}
	
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
