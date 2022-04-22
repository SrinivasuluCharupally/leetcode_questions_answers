#include<iostream>
#include<vector>

#include<bits/stdc++.h>

using namespace std;



void recursionWithouForLoop(int *input, int start, int end, vector<int> &tempArray, vector<vector<int>> &resultMatrix) {
//	if(start >= end) return;

	if(start >= end ) {
                std::vector<vector<int>>::iterator it;
	        it = std::find (resultMatrix.begin(), resultMatrix.end(), tempArray);
		if (it == resultMatrix.end()) resultMatrix.push_back(tempArray);

		return;
	}

	else {
		recursionWithouForLoop(input, start+1, end, tempArray, resultMatrix);
		tempArray.push_back(input[start]);
		recursionWithouForLoop(input, start+1, end, tempArray, resultMatrix);
		tempArray.pop_back();
	}
}



int main() {
	int input[3] = {1,2,2};
	int start = 0, end = sizeof(input) / sizeof(int);

	vector<int> tempArray2;
	vector<vector<int>> resultMatrix2;
	recursionWithouForLoop(input, start, end, tempArray2, resultMatrix2);


	for(int i = 0; i < resultMatrix2.size(); i++) {
		printf(" \n ");
		for(int j = 0; j < resultMatrix2[i].size(); j++)
			cout << resultMatrix2[i][j];
		printf(" \n ");
	}

}
