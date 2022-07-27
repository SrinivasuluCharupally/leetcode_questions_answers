#include<iostream>

using namespace std;

typedef struct node {
	int val;
	node *next=NULL;
	node(int i) : val(i), next(NULL) {}
} node;

int n = 2;

void recursion(node *head, node *tail) {
	if(tail == NULL) return;

	recursion(head, tail->next);
	while(n>=1) {
		node *tmp = head;
		head = head->next;
		tmp->next = NULL;
		tail->next = tmp;
		tail = tail->next;
		n--;
		tmp = head;
		while(tmp != NULL) { cout << tmp->val << " "; tmp = tmp->next; }
		cout << endl;
	}
}

int main() {
	node *head = new node(1);
	head->next = new node(2);
	head->next->next = new node(3);
	head->next->next->next = new node(4);
	
	node *tail=head;

	recursion(head, tail);
}
