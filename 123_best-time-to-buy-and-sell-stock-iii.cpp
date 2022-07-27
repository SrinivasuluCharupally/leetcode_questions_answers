#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void recursion(vector<int> input, int &index, int &buyIndex, int &sellIndex, vector<int> &profit) {
	if(index > input.size() ) return;

//	buyIndex = input[buyIndex] > input[index] ? index : buyIndex;

	if(input[buyIndex] > input[index] ) {
		buyIndex = index;
		sellIndex = buyIndex+1;	
		for(int i = sellIndex; i < input.size(); ++i) 
			sellIndex = input[i] >= input[sellIndex] ? i : sellIndex;
		profit.push_back(abs(input[buyIndex] - input[sellIndex]));

	}

	index = index + 1;
	recursion(input, index, buyIndex, sellIndex, profit);


}


int main() { 
	vector<int> input = {7,2,6,3,1,4};
	vector<int> profit = {0};
	int buyIndex = 0;
	int sellIndex = 0;
	int index = 1;

	recursion(input, index, buyIndex, sellIndex, profit);
	//cout << "Max Profit : " << profit << endl;
	sort(profit.begin(), profit.end());

	for(int i = profit.size()-1; i >= profit.size()-2; --i) 
		cout << profit[i] << " " ;
	cout << endl;
}
