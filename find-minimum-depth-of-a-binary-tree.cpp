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



int height_function(node *head) {
	if(!head) return 0;

	
		int l = height_function(head->left)+1;
		int r = height_function(head->right)+1;
	
//		if(abs(l-r) > 1) { return -1; }
		 	return l>r ? r : l;
	

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

	int h = height_function(head);
 	if(h == -1) { cout << "Not a Balanced Tree" << endl; }
	else cout << "Height of given tree " << h << endl;

	
}
