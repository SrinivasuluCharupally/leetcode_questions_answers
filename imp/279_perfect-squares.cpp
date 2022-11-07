#include <bits/stdc++.h>
using namespace std;
 
void combinationSum(
    vector<int> list, int N,
    int ind, vector<int> perfSquares)
{
 
    if (N < 0 || ind == list.size())
        return;
 
    if (N == 0)
    {
 
        for (int i : perfSquares)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
 
    // Do not include the current element
    combinationSum(list, N, ind + 1, perfSquares);
 
    // Include the element at current index
    perfSquares.push_back(list[ind]);
 
    combinationSum(list, N - list[ind], ind, perfSquares);
 
    // Remove the current element
    perfSquares.pop_back();
}
 
void sumOfPerfectSquares(int N)
{
 
    vector<int> list;
    int sqrtN = (int)(sqrt(N));
 
    for (int i = 2; i <= sqrtN; i++)
    {
        list.push_back(i * i);
    }
    vector<int> perfSquares;
    combinationSum(list, N, 0,
                   perfSquares);
}
 
int main()
{
    int N = 12;
 
    sumOfPerfectSquares(N);
    return 0;
}
 
