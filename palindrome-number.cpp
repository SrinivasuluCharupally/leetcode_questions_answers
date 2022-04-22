#include<iostream>

using namespace std;

void recursion(int &input, int &output, int source) {
	if(input <= 0) { if(source == output ) cout << "Is a palindrom" << endl;
			 else cout << "Not a Palindrom" << endl; 
			 return;
	}

	output = (output *10) + input % 10;
	input /= 10;

	recursion(input, output, source);
}

int main() {
	int input = 121, output = 0;
	int source = input;

	if(input < 0) { cout << "Not a palindrom" << endl; }
	else { recursion(input, output, source); }

}
