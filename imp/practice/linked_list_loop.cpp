#include<iostream>


using namespace std;

typedef struct Node {
	int data;
	Node *next = NULL;
	Node(int d) : data(d) { }
}Node;

typedef struct myhash{
	int key;
	int val;
	myhash *next;
} myhash;

Node* recursion( Node *head, Node *runner, Node *doublerunner) {
	if(runner == doublerunner) return runner;
	runner = runner->next;
	doublerunner = doublerunner->next->next;
	return recursion(head, runner, doublerunner);
	

}

void removeLoop(Node *loop, Node *mover) {
	if(loop == mover->next)  { mover->next = NULL; return ; }
	mover = mover->next;
	return removeLoop(loop, mover);
}

int main() {
	Node *head = new Node(1);
	head->next = new Node(7);
	head->next->next = new Node(2);
	head->next->next->next = new Node(3);
	head->next->next->next->next = new Node(4);
	head->next->next->next->next->next = head->next->next;
	Node *loop = recursion(head, head, head->next);
	cout << loop->data  << endl;

	myhash **h = new myhash * [10]; // here * is not multiplication, it's myhash * pointer

	for(int i = 0; i < 10; ++i) {
		cout << h[i] << endl;
	}

	int *p = new int{2};
	cout << *p << endl;

	int *p1 = new int[3] {1,2,3};

	for(int i = 0; i < 3; i++) cout << p1[i] << endl;

	int **dp = new int * 5 ;

	return 0;
}
