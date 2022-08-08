#include<iostream>
#include<vector>

using namespace std;

void recursion(vector<int> input, int &index, int &profit) {
	if(index >= input.size()) { cout << "Total Profit " << profit << endl; return; }

	int min = input[index]; int buyIndex=index;
	while( min > input[index+1] && index+1 < input.size() ) { min = input[index+1]; buyIndex = index+1; index +=1; }

	index += 1;
	int sellIndex = index, max = input[index];
	while(max < input[index+1] && index+1 < input.size()) { max = input[index+1] ; sellIndex = index+1; index +=1; }

	profit += abs(input[sellIndex] - input[buyIndex]);

	index += 1;
	recursion(input, index, profit);	

		
}


int main() {
	vector<int> input = {3,2,6,5,0,3};
	int profit =0;
	int index = 0;
	recursion(input, index, profit);
}
