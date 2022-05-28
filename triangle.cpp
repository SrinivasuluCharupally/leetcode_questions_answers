#include<iostream>
#include<vector>

using namespace std;

void recursion( vector<vector<int>> input, int &rowIndex, int &elementIndex, int &sum) {
	if(rowIndex >=input.size()) { cout << "Minimam Path Sum : " << sum << endl; return; }

	if(rowIndex ==0 ) { 
		sum = input[rowIndex][elementIndex]; 
		rowIndex = rowIndex+1;
		recursion(input, rowIndex, elementIndex, sum);
	}

	else {
		elementIndex =  (input[rowIndex][elementIndex] > input[rowIndex][elementIndex+1] ? elementIndex+1 : elementIndex) ;
		sum = sum + input[rowIndex][elementIndex];
		rowIndex =rowIndex + 1;
                recursion(input, rowIndex, elementIndex, sum);
	}

}


int main() {
	vector<vector<int>> input = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};

	int rowIndex=0, elementIndex=0, sum=0;

	recursion(input, rowIndex, elementIndex, sum);
}
