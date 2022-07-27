#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int sum(vector<int> output) {
	int sum = 0;
	for(int i = 0; i < 4; i ++) sum += output[i];

	return sum;
}

void print(vector<int> output) {
		for(int i = 0; i < output.size(); i++) {
			cout << output[i] << " ";
		}
		cout << endl;
}
void recursion(vector<int> &input, int index, vector<int> &output, int &target) {
	if(index >= input.size()) { 
	  if( output.size() == 4 && sum(output) == target) {
		print(output);
	   }
	  return;
	}
	
	else { 
		recursion(input, index+1, output, target);
	        output.push_back(input[index]);
		recursion(input, index+1, output, target);
		output.pop_back() ;
	}

}

int main() {
	vector<int> input = {1,0,-1,0,-2,2}; // -2, -1, 0, 0, 1, 2

	sort(input.begin(), input.end());

	vector<int> output;
	int index = 0; 
	int target = 0;
	//recursion(input, index1, index2, index3, index4, output, localsum, target)
	recursion(input, index, output, target);

}
