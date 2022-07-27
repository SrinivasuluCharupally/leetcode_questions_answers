#include<iostream>
#include<vector>

using namespace std;

void recursion(vector<int> input, int &index, int &buyIndex, int &sellIndex, int &profit) {
	if(index > input.size() ) return;

	buyIndex = input[buyIndex] > input[index] ? index : buyIndex;
	index = index + 1;

	if(buyIndex) {
		sellIndex = buyIndex+1;	
		for(int i = sellIndex; i < input.size(); ++i) 
			sellIndex = input[i] >= input[sellIndex] ? i : sellIndex;
		profit = profit < abs(input[buyIndex] - input[sellIndex]) ? abs(input[buyIndex] - input[sellIndex]) : profit ;

	}

	recursion(input, index, buyIndex, sellIndex, profit);


}


int main() { 
	vector<int> input = {7,2,6,3,1,4};
	int profit = 0;
	int buyIndex = 0;
	int sellIndex = 0;
	int index = 1;

	recursion(input, index, buyIndex, sellIndex, profit);
	cout << "Max Profit : " << profit << endl;
}
