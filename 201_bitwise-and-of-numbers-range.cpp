// https://www.geeksforgeeks.org/bitwise-and-or-of-a-range/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
int andOperator(int a, int b) {
      // ShiftCount variables counts till which bit every value will convert to 0
      int shiftcount = 0;
    //Iterate through every bit of a and b simultaneously
      //If a == b then we know that beyond that the and value will remain constant
      while(a != b and a > 0) {
          shiftcount++;
          a = a >> 1;
          b = b >> 1;
    }
      return int64_t(a << shiftcount);
}
 
int32_t main() {
    int a = 10, b = 15;
    cout << andOperator(a, b) << endl;
    return 0;
}

