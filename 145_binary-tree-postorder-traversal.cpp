#include<bits/stdc++.h>
using namespace std;
 
/* A Binary Tree node */
class TNode
{
    public:
    int data;
    TNode* left;
    TNode* right;

    TNode(int i) : data(i), left(NULL), right(NULL) {}
};
 
TNode* newNode(int data);
 
 
void postOrder(TNode* node)
{
    if (node == NULL)
        return;

    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}
 
// Driver Code
int main()
{

    TNode *root = new TNode(1);
    root->right = new TNode(2);
    root->right->left = new TNode(3);

    cout << "PreOrder Traversal of constructed BST \n";
    postOrder(root);
    cout << endl;

    return 0;
}
 
