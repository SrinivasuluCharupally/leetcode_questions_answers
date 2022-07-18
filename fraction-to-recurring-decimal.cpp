#include <bits/stdc++.h>
using namespace std;
 
string fractionToDecimal(int numr, int denr)
{
    string res;  
    map<int, int> mp;
    mp.clear();
 
    int rem = numr % denr;
 
    while ((rem != 0)
           && (mp.find(rem) == mp.end()))
    {
        mp[rem] = res.length();
        rem = rem * 10;
 
        int res_part = rem / denr;
        res += to_string(res_part);
 
        rem = rem % denr;
    }
 
    return (rem == 0) ? "" : res.substr(mp[rem]);
}
 
int main()
{
    int numr = 50, denr = 22;
    string res = fractionToDecimal(numr, denr);
    if (res == "")
        cout << "No recurring sequence";
    else
        cout << "Recurring sequence is " << res;
    cout << endl;
    return 0;
}

