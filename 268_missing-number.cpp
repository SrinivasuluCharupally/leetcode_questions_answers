#include<iostream>
#include<vector>

using namespace std;


void recursion(vector<int> input, bool checker[]) {
	static int index = 0;
	if(index >= input.size()) return;

	checker[input[index]] = true;
}


int main() {
	vector<int>  input = {9,6,4,2,3,5,7,0,1};
	const int n = input.size();
	static bool checker[n] = {false};
        	
	recursion(input, checker);

}
