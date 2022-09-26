#include<iostream>
#include<vector>

using namespace std;


void recursion( vector<int> input ) {
	static int index = 0;
	if(index >= input.size()) return;

	cout << "[" << input[index] << "," ;

	while(input[index]+1 == input[index+1]) {
		index += 1;
	}
	index += 1;
	cout << input[index-1] << "]" << endl;
	
	recursion(input);
}


int main() {
	vector<int> input = {0,2,3,4,6,8,9};

	recursion(input);

}
