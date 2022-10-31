#include<iostream>

using namespace std;


void recursion(int &input, int &result) {
	if(input <= 0 && result > 9 ) { input = result; result = 0; }
	else if(result < 10 && input <= 0) return;

	result += input %10;
	input /= 10;
	recursion(input, result);
}


int main() {

	int input = 38;
	int result = 0;
	recursion(input, result);
	cout << result << endl;
}
