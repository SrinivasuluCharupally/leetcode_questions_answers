// https://www.geeksforgeeks.org/check-if-two-given-strings-are-isomorphic-to-each-other/
// Isomorphic mean = mapping first char in str1 to first char in str2... 
// aab = ccd -> true
// aab != ced -> false because second char 'a' is pointing to different match in str2
//
#include <bits/stdc++.h>
using namespace std;
#define MAX_CHARS 26
 
bool areIsomorphic(string str1, string str2)
{
    int n = str1.length(), m = str2.length();
 
    if (n != m)
        return false;
 
    int count[MAX_CHARS] = { 0 };
    int dcount[MAX_CHARS] = { 0 };
 
    // Process all characters one by one
    for (int i = 0; i < n; i++) {
        count[str1[i] - 'a']++;
        dcount[str2[i] - 'a']++;
    }
        // For string to be isomorphic the previous counts
        // of appearances of
        // current character in both string must be same if
        // it is not same we return false.
   
   
          //before it was not working for the test case mentioned below(wrong output)
          // str1 = "aba" , str2 = "xyy"
      for(int i= 0; i < n; i++) {
        if (count[str1[i] - 'a'] != dcount[str2[i] - 'a']) {
            return false;
        }
    }
    return true;
}
 
// Driver Code
int main()
{
    cout << areIsomorphic("aab", "xxy") << endl;
    cout << areIsomorphic("aba", "xyy") << endl;
    return 0;
}

