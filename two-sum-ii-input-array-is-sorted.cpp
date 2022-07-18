#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int compare(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

typedef struct mySum {
	int value;
	int index;
} mySum;

void recursion(int *input, int start, int inputSize, int target, vector<mySum> &sumArray, int sum, vector<vector<mySum>> &resultMatrix) {
	if(start >= inputSize) return;
	if(sum >= target) {
		if(sum == target) {
			resultMatrix.push_back(sumArray);

		}

		return;
	}
		mySum tmp;
		tmp.value = input[start];
		tmp.index = start;

	sumArray.push_back(tmp);
	sum += input[start];
	recursion(input, start+1, inputSize, target, sumArray, sum, resultMatrix);
	
	sum = sum - (sumArray[sumArray.size() - 1]).value;
	sumArray.pop_back();
	recursion(input, start+1, inputSize, target, sumArray, sum, resultMatrix);	


}

int main() {
	int input[4] = {2,7,11,15}; //  {10,1,2,7,6,1,5}; // 1,1,2,5,6,7,10
	int target = 9, sum=0, position=0;
	int inputSize = sizeof(input) / sizeof(int);

	qsort(input, inputSize, sizeof(int), compare);

	cout << "Given input array " ;
	for(int i = 0; i < inputSize; i++)
		printf(" %d ", input[i]);
	cout << endl;

	vector<mySum> sumArray;
	vector<vector<mySum>> resultMatrix;
	recursion(input, 0, inputSize, target, sumArray, sum, resultMatrix );
	cout << "Target Sum is : " << target << endl;

	for(int i = 0; i < resultMatrix.size(); i++) {
		printf(" \nIndex : ");
		for(int j =0; j < resultMatrix[i].size(); j++) {
			printf(" %d ", resultMatrix[i][j].index);
		}
	}
	cout << endl;

}
