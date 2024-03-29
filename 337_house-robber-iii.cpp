#include<iostream>
#include<vector>
#include<list>
#include<map>

// use level order traverse , and find the sum in even level & odd level, display which is max

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


node *parent = NULL, *grandParent = NULL;
vector<int> mylist[5];

void recursion(node *head,  int level, int &levelSum) {
	if(head == NULL) { return; }	

	if(level == 1) { cout << head->data << " " ; levelSum += head->data; }

	else {
		if(level > 1) {
			recursion(head->left, level-1, levelSum);
			recursion(head->right, level-1, levelSum);
		}
	}

}

int height_function(node *head) {
	if(!head) return 0;
	int l = height_function(head->left)+1;
	int r = height_function(head->right)+1;

	return l>r ? l : r;

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
	multimap<int, int> resultArray;

	int h = height_function(head);
 	cout << "Height of given tree " << h << endl;

	int levelSumOdd=0, levelSumEven=0;

	for(int i =1 ; i <= h; i++) {
		cout << "Level " << i << "  :: " ;
		if(i%2 == 0) recursion(head, i , levelSumEven);
		else recursion(head, i, levelSumOdd);
		cout << endl;
//		cout << " Sum = " << levelSumEven << ", " << levelSumOdd << endl;
	}
	cout << "maximum amount of money the thief can rob == "	 <<  ( levelSumOdd > levelSumEven ? levelSumOdd : levelSumEven ) << endl ;
}
