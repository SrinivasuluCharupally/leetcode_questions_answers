#include<iostream>
#include<vector>

using namespace std;


int numDistinctUtil(string S, string T, int i, int j) {
  if (i < 0 || j < 0 || i < j)
    return 0;

//  cout << i << " " << j << endl;
  if (S[i]==T[j]) {
    if (j == 0)
      return numDistinctUtil(S, T, i-1, j) + 1;
    else {
      return numDistinctUtil(S, T, i-1, j) + numDistinctUtil(S, T, i-1, j-1);
    }
  }
  return numDistinctUtil(S, T, i-1, j);
}


int main() {
	string s1 = "rabbbit";
	string s2 = "rabbit";
	cout << numDistinctUtil(s1, s2, s1.size()-1, s2.size()-1) << endl;
}

