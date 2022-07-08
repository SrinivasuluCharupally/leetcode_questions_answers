#include<iostream>
#include<vector>
#include<set>
#include<string>

using namespace std;

void recursion(string input, int &index, int k, int &noOfOccurance, int &maxSubStringLength) {
	if(index >= input.size()) { cout << "maxSubStringLength " << maxSubStringLength << endl; return; }
	
	set<char> myset;
	int endIndex = index;
	while(myset.size() <= k && endIndex < input.size() ) {
		myset.insert(input[endIndex]);
		endIndex++;
	}

	maxSubStringLength = maxSubStringLength > (endIndex-index) ? maxSubStringLength : (endIndex-index);
	index += 1;

	recursion(input, index, k, noOfOccurance, maxSubStringLength);
}


int main() {
	string input = "aabacbebebe";
	int index = 0, k=3, noOfOccurance=0, maxSubStringLength=0;
	recursion(input, index,k, noOfOccurance, maxSubStringLength);
}
