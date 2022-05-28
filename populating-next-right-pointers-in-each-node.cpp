///https://www.tutorialcup.com/interview/tree/populating-next-right-pointers-in-each-node.htm
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// blueprint of the tree node
class Node
{
    public : 
    int data;
    Node *left, *right, *next;
    
    Node(int key)
    {
        data = key;
        left = right = next = NULL;
    }
};
// function that makes appropriate connections    
void connect(Node *root) 
{ 
    // create queue to hold nodes at same level  
    queue <Node*> q;
    
    // insert root node
    q.push(root); 
    
    // used to store the current node
    Node* temp = NULL; 
    
    while (!q.empty()) 
    { 
        int n = q.size(); 
        for (int i = 0; i < n; i++) 
        { 
            // previous stores last popped node from the queue
            Node* prev = temp; 
            temp = q.front();
            q.pop();
            /*
            when i = 0, prev is the first node of a level
            so we have to skip this node.
            and change next pointer from next node onwards
            */
            if (i > 0) 
                prev->next = temp;  
            if (temp->left != NULL) 
                q.push(temp->left); 
            if (temp->right != NULL) 
                q.push(temp->right); 
        } 
        // pointing last node of a particular level to null 
        temp->next = NULL;  
    } 
} 
// Function to print node values of a particular level
void printLevel(Node* root)
{
    if(root == NULL)
    {
        cout<<endl;
        return;
    }
    
    cout<<root->data<<" ";
    printLevel(root->next);
}
int main()
{
    /* create the binary tree*/
    Node *root = NULL;
    
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    
    connect(root);
        
    cout<<"1st Level : ";
    printLevel(root);
    
    cout<<"2nd Level : ";
    printLevel(root->left);
    
    cout<<"3rd Level : ";
    printLevel(root->left->left);
    
    return 0;
}
