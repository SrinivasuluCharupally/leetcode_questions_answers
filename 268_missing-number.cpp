#include<iostream>
#include<vector>

using namespace std;


void recursion(vector<int> input, bool checker[]) {
	static int index = 0;
	if(index >= input.size()) return;

	checker[input[index]] = true;
	index += 1;
	recursion(input, checker);
}


int main() {
	vector<int>  input = {9,6,4,2,3,5,7,0,1};
	const int n = input.size();
	static bool checker[10] = {false};
        	
	recursion(input, checker);
//	while(n>=0) if(checker[n-1] 

}
