#include<iostream>
#include<vector>

using namespace std;


void recursion( int n, int open, int close, vector<string> &result, string &str) {
	if(close == n )  { result.push_back(str); return; }

	else {
		if(open < n) { str += "{";
			recursion(n, open+1, close, result, str);
			str.pop_back();
		}
		if(close < open) {
			str +=  "}";
			recursion(n, open, close+1, result, str);
			str.pop_back();
		}
	}

	

}

int main() {
	int n = 3;
	
	vector<string> result;
	string str = "";
	int open = 0, close = 0;

	recursion(n, open, close, result, str);
	
	for(int i = 0; i <result.size(); i++) {
		cout << result[i] << endl;
	}
}
