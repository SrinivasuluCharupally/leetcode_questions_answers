#include<iostream>

using namespace std;

typedef struct node {
	int val;
	node *next = NULL;
	node(int i) : val(i), next(NULL) {}
} node;





node* reverse(node* head, int k)
{
    // base case
    if (!head)
        return NULL;
    node* current = head;
    node* next = NULL;
    node* prev = NULL;
    int count = 0;
 
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
 
    /* next is now a pointer to (k+1)th node
    Recursively call for the list starting from current.
    And make rest of the list as next of first node */
    if (next != NULL)
        head->next = reverse(next, k);
 
    /* prev is new head of the input list */
    return prev;
}


int main() {
	node *head = new node(1);
	head->next = new node(2);
	head->next->next = new node(3);
	head->next->next->next = new node(4);
	head->next->next->next->next = new node(5);
	head->next->next->next->next->next = new node(6);

	node *base = head;
	while(head) { cout << head->val << " " ; head = head->next; }
	cout << endl;
	
	node *result = reverse(base, 3);
	while(result) { cout << result->val << " " ; result = result->next; }
	cout << endl;
}
