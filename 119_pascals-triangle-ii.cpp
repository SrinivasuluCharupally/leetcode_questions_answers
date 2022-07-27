//https://www.geeksforgeeks.org/pascal-triangle/

#include <bits/stdc++.h>
 
using namespace std;
void printPascal(int line)
{
     
//for (int line = 1; line <= n; line++)
//{
    int C = 1; // used to represent C(line, i)
    for (int i = 1; i <= line; i++)
    {
         
        // The first value in a line is always 1
        cout<< C<<" ";
        C = C * (line - i) / i;
    }
    cout<<"\n";
//}
}
 
// Driver code
int main()
{
    int line = 4;
    printPascal(line);
    return 0;
}

