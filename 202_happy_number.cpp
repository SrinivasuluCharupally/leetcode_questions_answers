#include <bits/stdc++.h>
using namespace std;
 
bool isHappynumber(int n)
{
    if (n == 1)
        return true;
    int sum = n, x = n;
    while (sum > 9) {
        sum = 0;
        while (x > 0) {
            int d = x % 10;
            sum += d * d;
            x /= 10;
        }
        if (sum == 1)
            return true;
        x = sum;
    }
    return false;
}
 
int main()
{
    int n = 13;
 
    if (isHappynumber(n))
        cout << n << " is a Happy number";
    else
        cout << n << " is not a Happy number";
    cout << endl;
    return 0;
}

