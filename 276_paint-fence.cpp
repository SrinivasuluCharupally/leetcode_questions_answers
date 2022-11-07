// source : https://www.geeksforgeeks.org/painting-fence-algorithm/
// remember the logic ...
#include <bits/stdc++.h>
using namespace std;
 
// Returns count of ways to color k posts
long countWays(int n, int k)
{
    long dp[n + 1];
    memset(dp, 0, sizeof(dp));
    long long mod = 1000000007;
 
    dp[1] = k;
    dp[2] = k * k;
 
    for (int i = 3; i <= n; i++) {
        dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod;
    }
 
    return dp[n];
}
 
// Driver code
int main()
{
    int n = 2, k = 4;
    cout << countWays(n, k) << endl;
    return 0;
}

