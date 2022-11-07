// https://tenderleo.gitbooks.io/leetcode-solutions-/content/GoogleHard/272.html
// we need k no.of different values closest to the given number
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

static int given_Size = 3; // you need to find 3 different numbers close to the target from the BST.

void maxDiffUtil(struct Node *ptr, int k, int &min_diff,
                                      vector<int> &min_diff_key)
{
    if (ptr == NULL || min_diff_key.size() == given_Size)
        return ;
 
    if (ptr->key == k)
    {
        min_diff_key.push_back(k);
    //    return;
    }
 
    if (min_diff > abs(ptr->key - k) && min_diff_key.size() < given_Size)
    {
        min_diff = abs(ptr->key - k);
        min_diff_key.push_back(ptr->key);
    }
 
   // if (k < ptr->key)
        maxDiffUtil(ptr->left, k, min_diff, min_diff_key);
   // else
        maxDiffUtil(ptr->right, k, min_diff, min_diff_key);
}
 
void maxDiff(Node *root, int k)
{
    int min_diff = INT_MAX;
    vector<int> min_diff_key = {-1 };
 
    maxDiffUtil(root, k, min_diff, min_diff_key);
    // print all values hereeeeeeeeeeee from min_diff_key container 
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
    maxDiff(root, k) ;
    
    return 0;
}

