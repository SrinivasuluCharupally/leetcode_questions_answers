#include<iostream>

using namespace std;

void recursion(int &input) {
	if(input == 1) { cout << "true" << endl; return; }
	else if(input % 2 == 1) { cout << " false " << endl ; return; }
	else { 

		input /= 2;
		recursion(input);
	}
}


int main() {
	int input = 16;
	recursion(input);

}
