#include<iostream>

using namespace std;
int inputLength = 5;

void recursion(int input[] ) {
	static int index = 0, noOfZeros = 0;
	if(index >= inputLength) return;

	while(input[index] == 0) { noOfZeros += 1; index += 1; }
	
	for(int i = 0; i < noOfZeros && input[index] != 0; i++) { swap(input[index], input[index-noOfZeros]); index += 1; }
	
	recursion(input);
	
}

int main() {
	int input[] ={0,1,0,3,12};

	recursion(input);
	for(int i = 0; i < inputLength; i++) cout << input[i] << " " ;
	cout << endl;
}
