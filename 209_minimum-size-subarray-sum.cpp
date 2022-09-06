#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int compare(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

void recursion(int *input, int start, int inputSize, int target, vector<int> &sumArray, int sum, vector<int> &resultMatrix) {
	if(start >= inputSize) return;
	if(sum >= target) {
		if(resultMatrix.size() == 0) resultMatrix = sumArray;

		else if(resultMatrix.size() >= sumArray.size()) {
			resultMatrix = sumArray;
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
	int input[7] = {10,1,2,7,6,1,5}; // 1,1,2,5,6,7,10
	int target = 8, sum=0, position=0;
	int inputSize = sizeof(input) / sizeof(int);

	qsort(input, inputSize, sizeof(int), compare);

	cout << "Given input array " ;
	for(int i = 0; i < inputSize; i++)
		printf(" %d ", input[i]);

	vector<int> sumArray;
	vector<int> resultMatrix;

	recursion(input, 0, inputSize, target, sumArray, sum, resultMatrix );

	cout << endl << "Minimal Sub Array " ;
		for(int j =0; j < resultMatrix.size(); j++) {
			printf(" %d ", resultMatrix[j]);
		}
	cout << endl;

}
