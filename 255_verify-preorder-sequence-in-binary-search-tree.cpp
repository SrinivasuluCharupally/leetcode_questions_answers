#include <bits/stdc++.h>
using namespace std;
 
void buildBST_helper(int& Index, int n, int pre[],
                     int min, int max)
{
    if (Index >= n)
        return;
 
    if (min <= pre[Index] && pre[Index] <= max) {
        int rootData = pre[Index];
        Index++;
 
        buildBST_helper(Index, n, pre, min, rootData);
 
        buildBST_helper(Index, n, pre, rootData, max);
    }
}
 
bool canRepresentBST(int arr[], int N)
{
    int min = INT_MIN, max = INT_MAX;
    int Index = 0;
 
    buildBST_helper(Index, N, arr, min, max);
 
    return Index == N;
}
 
int main()
{
 
    int preorder1[] = { 2, 4, 3 };
    /*
            2
            \
             4
            /
           3
 
*/
    int n1 = sizeof(preorder1) / sizeof(preorder1[0]);
 
    if (canRepresentBST(preorder1, n1))
        cout << "\npreorder1 can represent BST";
    else
        cout << "\npreorder1 can not represent BST  :(";
 
    int preorder2[] = { 5, 3, 4, 1, 6, 10 };
    int n2 = sizeof(preorder2) / sizeof(preorder2[0]);
    /*
                    5
         /     \
       3         1
         \     /  \
         4    6    10
 
*/
    if (canRepresentBST(preorder2, n2))
        cout << "\npreorder2 can represent BST";
    else
        cout << "\npreorder2 can not represent BST  :(";
 
    int preorder3[] = { 5, 3, 4, 8, 6, 10 };
    int n3 = sizeof(preorder3) / sizeof(preorder3[0]);
    /*
                    5
         /     \
       3         8
         \     /  \
         4    6    10
 
*/
    if (canRepresentBST(preorder3, n3))
        cout << "\npreorder3 can represent BST";
    else
        cout << "\npreorder3 can not represent BST  :(";
 
    return 0;
}
 
