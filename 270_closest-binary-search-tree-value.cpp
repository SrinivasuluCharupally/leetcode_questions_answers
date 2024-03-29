#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
    int key;
    struct Node* left, *right;
};
 
struct Node* newnode(int key)
{
    struct Node* node = new (struct Node);
    node->key = key;
    node->left = node->right  = NULL;
    return (node);
}
 
void maxDiffUtil(struct Node *ptr, int k, int &min_diff,
                                      int &min_diff_key)
{
    if (ptr == NULL)
        return ;
 
    if (ptr->key == k)
    {
        min_diff_key = k;
        return;
    }
 
    if (min_diff > abs(ptr->key - k))
    {
        min_diff = abs(ptr->key - k);
        min_diff_key = ptr->key;
    }
 
    if (k < ptr->key)
        maxDiffUtil(ptr->left, k, min_diff, min_diff_key);
    else
        maxDiffUtil(ptr->right, k, min_diff, min_diff_key);
}
 
int maxDiff(Node *root, int k)
{
    int min_diff = INT_MAX, min_diff_key = -1;
 
    maxDiffUtil(root, k, min_diff, min_diff_key);
 
    return min_diff_key;
}
 
int main()
{
    struct Node *root = newnode(9);
    root->left    = newnode(4);
    root->right   = newnode(17);
    root->left->left = newnode(3);
    root->left->right = newnode(6);
    root->left->right->left = newnode(5);
    root->left->right->right = newnode(7);
    root->right->right = newnode(22);
    root->right->right->left = newnode(20);
    int k = 18;
    cout << maxDiff(root, k) << endl;
    return 0;
}

