#include<iostream>

using namespace std;


void recursion(int input, int &sqrt) {
	if(sqrt*sqrt > input) { cout << "sqrt of given number is " << sqrt - 1 << endl; return; }
	else {
		sqrt += 1;
		recursion(input, sqrt);
	}

}


int main() {
	int input = 8;
	int sqrt =1;

	recursion(input, sqrt);
}
