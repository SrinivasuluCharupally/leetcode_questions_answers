#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

typedef struct TreeNode {
	int data;
	TreeNode *left=NULL, *right=NULL;
	TreeNode(int d) : data(d) {}
}TreeNode;


TreeNode* convertToTree(vector<int> input, int start, int end) {
	if(start >= end) return NULL;
	
	int mid = (start + end)  / 2;
	TreeNode *head = new TreeNode(input[mid]);
	head->left = convertToTree(input, start, mid);
	head->right = convertToTree(input, mid+1, end);
	return head;

}

int levelOrder(TreeNode *head, map<int, vector<int>> &mymap) {
	if(head == NULL) return 0;

	int l = levelOrder(head->left, mymap) + 1;
	int r = levelOrder(head->right, mymap) + 1;

	if(l>r) { mymap[l].push_back(head->data); return l; }
	else { mymap[r].push_back(head->data); return r; }
}

void print(TreeNode *head) {
	if(head == NULL) return;
	cout << head->data << " ";
	print(head->left);
	print(head->right);
}

void verticalOrder(TreeNode *head, map<int, vector<int>> &mymap, int hd) {
	if(head == NULL) return;

	mymap[hd].push_back(head->data);
	verticalOrder(head->left, mymap, hd-1);
	verticalOrder(head->right, mymap, hd+1);
}

int main() {
	vector<int> input = {2,3,4,5,6,1};
	sort(input.begin(), input.end());
for(int i = 0; i < input.size(); i++) { cout << input[i] << endl; }

	int start = 0, end = input.size();
	TreeNode *head = convertToTree(input, start, end);
	TreeNode *tmp = head;
	print(tmp);
	cout << endl;
	map<int, vector<int>> mymap;
	TreeNode *headV = head;
	levelOrder(head, mymap);

	map<int, vector<int>>::iterator itr;
	for( itr = mymap.begin(); itr != mymap.end(); ++itr) {
		for(int i =0; i < itr->second.size(); ++i) {
		 cout << (itr->second)[i] << " ";
		}
		cout << endl;
	}
	
	map<int, vector<int>> myVmap;
	int hd = 0;
	verticalOrder(headV, myVmap, hd);
	

	cout << "Vertical Order " << endl;
	map<int, vector<int>>::iterator itr1;
	for( itr1 = myVmap.begin(); itr1 != myVmap.end(); ++itr1) {
		for(int i =0; i < itr1->second.size(); ++i) {
			cout << (itr1->second)[i] << " " ;
		}
		cout << endl;
	}	

}
