#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void recursion(vector<int> input, int &index, int &maxLength) {
	if(index >= input.size()-1) return;
	
	int count = 0;
	while(input[index] + 1 == input[index+1]) {
		if(index+1 == input.size()-2) count = count+2;
		else count++;

		index = index+1;
	}
	if(count == 0) index = index+1;
	maxLength = count > maxLength ? count : maxLength;
	recursion(input, index, maxLength);
	return;
}


int main() {
	vector<int> input = { 0,3,7,2,5,8,4,6,0,1};
	sort(input.begin(), input.end());
	int index = 0, maxLength=0;
	recursion(input, index, maxLength);
	cout << maxLength << endl;
}
