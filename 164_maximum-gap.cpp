#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void recursion(vector<int> input, int &index, int &maxDiff) {
	if(index >= input.size()) { cout << "Max gap " << maxDiff << endl; return; }

	else {
		int diff = abs(input[index] - input[index-+1]);
		maxDiff = diff > maxDiff ? diff : maxDiff;
		index += 1;

	        recursion(input, index, maxDiff);
	}
}	

int main() {
	vector<int> input = {1, 14, 11, 51, 15}; // { 1, 11, 14, 15, 51 };
	sort(input.begin(), input.end());
	//input.sort();

	int index=0, maxDiff=0;

	recursion(input, index, maxDiff);
}
