#include<iostream>
#include<vector>


using namespace std;


void recursion(vector<int> input, int start, int end, vector<int> &tmpArray, vector<vector<int>> &resultArray, int &sum) {
	if(start >= end) return;

	if(sum == 0) {
		resultArray.push_back(tmpArray);
	}
	sum += input[start];
	tmpArray.push_back(input[start]);
//cout << sum << endl;	
	recursion(input, start+1, end, tmpArray, resultArray, sum);

	sum = 0;
	tmpArray.clear();
	//sum -= tmpArray[tmpArray.size()-1];
	//tmpArray.pop_back();
	recursion(input, start+1, end, tmpArray, resultArray, sum);




}

int main() {
	vector<int> input = {-2,-3,4, -1, -2, 1,5,3};

	int start = 0, end = input.size(), sum=0;

	vector<int> tmpArray;
	vector<vector<int>> resultArray;

	recursion(input, start, end, tmpArray, resultArray, sum);

	for(int i =0; i < resultArray.size(); ++i) {
		for(int j = 0; j < resultArray[i].size(); ++j) {
			cout << resultArray[i][j] << " "; }
		cout << endl;
	}

}
