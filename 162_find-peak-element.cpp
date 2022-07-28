#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void recursion(vector<int> input, int &index, int &maxValue, int &maxIndex) {
	if(index >= input.size()-1) { cout << "Max Value " << maxValue << " at Index " << maxIndex << endl; return; }
	else {
		int localmaxIndex = (input[index] > input[index-1]  && input[index] > input[index+1]) ? index : 0;
		if(localmaxIndex) { maxIndex = input[localmaxIndex] > input[maxIndex] ? localmaxIndex : maxIndex; 
	       			maxValue = input[maxIndex];	}
		
		index += 1;
		recursion(input, index, maxValue, maxIndex);
	}	

}

int main() {
	vector<int> input = {1,2,1,3,5,6,4};

	int index = 1, maxValue = INT_MIN, maxIndex = 0;
	recursion(input, index, maxValue, maxIndex);
}

