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


node *parent = NULL, *grandParent = NULL;

void recursion(node *head,  node *parent, vector<int> &tmpArray, vector<vector<int>> &resultArray) {
	 if(head == NULL) { return ; }

	
	tmpArray.push_back(head->data);

	if(!head->left && !head->right) { resultArray.push_back(tmpArray);   }


  	recursion(head->left, head, tmpArray, resultArray);
        recursion(head->right, head, tmpArray, resultArray);
	tmpArray.pop_back();

	
	
}

int main() {
	node * head = new node(4);
	head->left = new node(2);
	head->right = new node(5);
	head->left->left = new node(1);
	head->left->right = new node(3);
	head->right->right = new node(6);

	node *parent=NULL;
	vector<int> tmpArray;
	vector<vector<int>> resultArray;

 	recursion(head, parent, tmpArray, resultArray);


	for(int i = 0; i < resultArray.size(); i++) {
		for(int j = 0; j < resultArray[i].size(); j++)
			cout << resultArray[i][j] << " " ;
		cout << endl;
	}

}
