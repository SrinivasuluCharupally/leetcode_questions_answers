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
 
TNode* sortedArrayToBST(int arr[],
                        int start, int end)
{
    /* Base Case */
    if (start > end)
    return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    //TNode *root = newNode(arr[mid]);
    TNode *root = new TNode(arr[mid]);
 
    /* Recursively construct the left subtree
    and make it left child of root */
    root->left = sortedArrayToBST(arr, start,
                                    mid - 1);
 
    /* Recursively construct the right subtree
    and make it right child of root */
    root->right = sortedArrayToBST(arr, mid + 1, end);
 
    return root;
}
 
void preOrder(TNode* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}
 
// Driver Code
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    /* Convert List to BST */
    TNode *root = sortedArrayToBST(arr, 0, n-1);
    cout << "PreOrder Traversal of constructed BST \n";
    preOrder(root);
    cout << endl;

    return 0;
}
 
