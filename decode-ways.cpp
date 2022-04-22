#include<iostream>
#include<string>

using namespace std;

int mod = 1000000007;
int countWays(string str, int start, int end) {
	if(start > end || (start == end && str[start] != '0')) {
		return 1;
	} 
	if (str[start] == '0') {
		return 0;
	}
	int ways = 0;
	ways = (ways + countWays(str, start + 1, end)) % mod;
	if (start < end && (str[start] == '1' || str[start] <= '2' && str[start + 1] <= '6') ){
		ways = (ways + countWays(str, start + 2, end)) % mod;
	} 
	return ways;
}
int numDecodings(string str) {
	int start = 0;
    return countWays(str, start, str.size() - 1);
}

int main() {
	string s = "226";
	cout << numDecodings(s) << endl;
}
