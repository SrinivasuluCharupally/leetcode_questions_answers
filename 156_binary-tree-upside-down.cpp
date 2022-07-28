#include<bits/stdc++.h>
using namespace std;
 
/* A Binary Tree node */
class TNode
{
    public:
    int data;
    TNode* left;
    TNode* right;
    TNode() : left(NULL), right(NULL) {}
    TNode(int i) : data(i), left(NULL), right(NULL) {}
};
 
TNode* newNode(int data);
 
TNode* upsideDownBinaryTree(TNode *root) {
        if (root == NULL || root->left == NULL) {
            return root;
        }
        
        TNode *left = upsideDownBinaryTree(root->left);
        root->left->left = root->right;
        root->left->right = root;
        
        root->left = NULL;
        root->right = NULL;
        
        return left;
}

void preOrder(TNode* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

//		1
//
//	     2     3
//
//	   4   5

int main()
{

    TNode *root = new TNode(1);
    root->left = new TNode(2);
    root->right = new TNode(3);
    root->left->left = new TNode(4);
    root->left->right = new TNode(5);

    cout << "PreOrder Traversal of constructed BST \n";
    TNode *head = root;
    preOrder(root);
     cout << endl;
    TNode *converted = upsideDownBinaryTree(head);
    
    preOrder(converted);    
    return 0;
}
 
