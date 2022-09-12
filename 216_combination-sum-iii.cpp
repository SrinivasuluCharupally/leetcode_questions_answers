#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int compare(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

void recursion(int *input, int start, int inputSize, int target, vector<int> &sumArray, int sum, vector<vector<int>> &resultMatrix) {
	if(start >= inputSize) return;
	if(sum >= target) {
		if(sum == target) {
			resultMatrix.push_back(sumArray);

		}

		return;
	}

	sumArray.push_back(input[start]);
	sum += input[start];
	recursion(input, start+1, inputSize, target, sumArray, sum, resultMatrix);
	
	sum = sum - sumArray[sumArray.size() - 1];
	sumArray.pop_back();
	recursion(input, start+1, inputSize, target, sumArray, sum, resultMatrix);	

}

int main() {
	int input[9] = {1,2,3,4,5,6,7,8,9};
	int target = 7, k = 3, sum=0;
	int inputSize = sizeof(input) / sizeof(int);

	qsort(input, inputSize, sizeof(int), compare);

	cout << "Given input array " ;
	for(int i = 0; i < inputSize; i++)
		printf(" %d ", input[i]);

	vector<int> sumArray;
	vector<vector<int>> resultMatrix;
//
	recursion(input, 0, inputSize, target, sumArray, sum, resultMatrix );

	for(int i = 0; i < resultMatrix.size(); i++) {

	    if(resultMatrix[i].size() == k) {
		printf(" \n");
		for(int j =0; j < resultMatrix[i].size(); j++) {
			printf(" %d ", resultMatrix[i][j]);
		}
	    }
	}
	cout << endl;

}
