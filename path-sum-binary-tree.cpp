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

void print(vector<int> paths, int i) {
	for(int m = i; m < paths.size(); m++)
		cout << paths[m] << " " ;
	cout << endl;
}



void findPath(node* root, vector<int> &paths, int targetValue) {
	if(!root) return;
	paths.push_back(root->data);
	findPath(root->left, paths, targetValue);
	findPath(root->right, paths, targetValue);

	int x = 0;
	for(int i = paths.size()-1; i >=0; i--) {
		x += paths[i];
		if(x == targetValue) { cout << "Path details :: " ; print(paths,i); }
	}
	paths.pop_back();
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

	int h = height_function(head);
 	cout << "Height of given tree " << h << endl;

	vector<int> paths;
	int targetValue = 15;
	findPath(head, paths, targetValue);
	
}
