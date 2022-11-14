// Successor: Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a binary search tree. You may assume that each node has a link to its parent.

//source for height calculation http://www.geeksforgeeks.org/sorted-array-to-balanced-bst/

// source for succesor is book
//				5
//		2					8
//	1		3		6			9
				
//			    4			7			10

#include<iostream>
#include<stdlib.h>
#include<list>

using namespace std;

typedef struct TreeNode {
	int data;
	TreeNode*  left = NULL;
	TreeNode* right = NULL;
} TreeNode;

TreeNode* ArrayToTree(int[], int, int);
//TreeNode* ArrayOfNodes = (struct TreeNode*) malloc(sizeof(TreeNode))[];

TreeNode* ArrayToTree(int arr[], int start, int end) {
	if(start >= end)  {
		return NULL;
	}
	TreeNode* newNode = (struct TreeNode*) malloc(sizeof(TreeNode));
	int mid = (end+start)/2;
	newNode->data = arr[mid];
	newNode->left = ArrayToTree(arr, start, mid);
	newNode->right = ArrayToTree(arr,mid+1, end);
	return newNode;
}

int height(TreeNode* Node) {
	if(Node == NULL) {
		return 0;
	}
	else {
		int lheight = height(Node->left);
		int rheight = height(Node->right);
		if(lheight > rheight)
			return (lheight+1);
		else return (rheight+1);
	}
}



TreeNode* recursion(TreeNode* n) {
	static bool found = false;
	static int target = 6;

	if(n == NULL) {
		return NULL;
	}
	





	recursion(n->left);

	if(found )  { cout << n->data << " " << endl; exit(0); }
	if(n->data == target) found = true;
	
	recursion(n->right);
}



int main() {
int a[10] = {1,2,3,4,5,6,7,8,9,10};

int n = sizeof(a)/sizeof(a[0]);
TreeNode* Tree = ArrayToTree(a, 0, n-1);

cout << "Tree created" << endl;

TreeNode* succesor = recursion(Tree);
}
