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

void recursion(node* insertposition, node* current, node *previous)
{
	if (!current) { 
 		return ;
	}

	if(current->val < 3 && insertposition == NULL) {  
		insertposition = current;
	}
	else if(current->val < 3 && current->next) {

		node *tmpcurrent = previous;
		node *tmp = insertposition->next;
		insertposition->next = current; // 1->2
		previous->next = current->next; // 3->5
		current->next = tmp; // 2->4
		insertposition = insertposition->next; // 2
		current = tmpcurrent; // 3
	}	
	else if(current->val < 3 && !current->next) {

		node *tmpcurrent = previous;
		node *tmp = insertposition->next;
		insertposition->next = current; // 1->2
		previous->next = NULL; //current->next; // 3->5
		current->next = tmp; // 2->4
		insertposition = insertposition->next; // 2
		current = tmpcurrent; // 3
	}

	previous = current;
	current  = current->next;

	
	recursion(insertposition, current, previous);

}


int main() {
	node *head = new node(1);
	head->next = new node(4);
	head->next->next = new node(3);
	head->next->next->next = new node(2);
	head->next->next->next->next = new node(5);
	head->next->next->next->next->next = new node(2);
	head->next->next->next->next->next->next = new node(6);
	head->next->next->next->next->next->next->next = new node(1);

	node *insertposition = NULL;
	node *current = head;
	node *previous = current;

	node *tmp = head;
	print(tmp);

	recursion(insertposition, current, previous);
	cout << "After sorting the list based on given condition " ;
	print(head);
}
