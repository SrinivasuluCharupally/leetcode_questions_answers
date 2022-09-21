#include<iostream>
#include<vector>
#include<list>
#include<map>


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
//    			      9	 
//



void height_function(node *head, int &countNodes) {
	if(!head) return ;
	
	countNodes += 1;	

	height_function(head->left, countNodes);
	height_function(head->right, countNodes);

}

int main() {
	node * head = new node(4);
	head->left = new node(2);
	head->right = new node(5);
	head->left->left = new node(1);
	head->left->right = new node(3);
	head->right->right = new node(6);

	head->right->right->left = new node(9);

	int  height = 0, sum=0;
	int countNodes = 0;

	height_function(head, countNodes);
	cout << "Total nodes of given tree " << countNodes << endl;

	
}
