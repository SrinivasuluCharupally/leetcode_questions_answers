#include<iostream>
#include<vector>
#include<climits>

using namespace std;

static int lowerLimit = -2, upperLimit = 2;
void recursion(int *input, int start, int end, int sum, vector<int> &tmpArray, vector<vector<int>> &resultMatrix) {
	if(start > end) return;
	if(sum >= lowerLimit && sum <= upperLimit) {
		resultMatrix.push_back(tmpArray);
	//	return;
	}
	
	
		tmpArray.push_back(input[start]);
		sum += input[start];
		recursion(input, start+1, end, sum, tmpArray, resultMatrix);

		sum -= tmpArray[tmpArray.size() -1];
		tmpArray.pop_back();
		recursion(input, start+1, end, sum, tmpArray, resultMatrix);
			

}

int main() {
	int input[] = {-2,5,-1};

	int arraySize = sizeof(input) / sizeof(int), sum = 0;
	vector<int> tmpArray;
	vector<vector<int>> resultMatrix;

	recursion(input, 1 , arraySize, input[0], tmpArray, resultMatrix);

	cout << resultMatrix.size() << endl;

//	for(int i = 0; i < resultMatrix.size(); i++) {
//		for(int j = 0; j < resultMatrix[i].size(); j++)
//			cout << resultMatrix[i][j] << " ";
//		cout << endl;
//	}
}
