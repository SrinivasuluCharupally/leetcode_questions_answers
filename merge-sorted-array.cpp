#include<bits/stdc++.h>
using namespace std;
 
void mergeArrays(int a[], int b[], int n, int m)
{
    // Declaring a map.
    // using map as a inbuilt tool
    // to store elements in sorted order.
    map<int, bool> mp;
     
    // Inserting values to a map.
    for(int i = 0; i < n; i++)
    mp[a[i]] = true;
     
    for(int i = 0;i < m;i++)
    mp[b[i]] = true;
     
    // Printing keys of the map.
    for(auto i: mp)
    cout<< i.first <<" ";
}
 
int main()
{
    int a[] = {1, 3, 5, 7}, b[] = {2, 4, 6, 8};
     
    int size = sizeof(a)/sizeof(int);
    int size1 = sizeof(b)/sizeof(int);
     
    // Function call
    mergeArrays(a, b, size, size1);
     
    return 0;
}
 
