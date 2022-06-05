#include<iostream>
#include<vector>

using namespace std;

typedef struct node {
	int data;
	node *right, *left;
	node(int i) : data(i), left(NULL), right(NULL) {} 
} node;
//
//		4	
//	2		5
//   1       3			6
//     
//



int recursion(node *head,  int sum) {
	if(head == NULL)  { 
		return 0; 
	}

	sum = (sum*10) + head->data; cout << sum << endl;


	if(head->left == NULL && head->right == NULL) return sum;

  	return recursion(head->left, sum) + recursion(head->right, sum);
	
}

int main() {
	node * head = new node(4);
	head->left = new node(2);
	head->right = new node(5);
	head->left->left = new node(1);
	head->left->right = new node(3);
	head->right->right = new node(6);

	int givenValue = 6, sum=0, tracker=0;
	vector<int> array;
 	cout << "Total of each path " << recursion(head, sum) << endl;

}
