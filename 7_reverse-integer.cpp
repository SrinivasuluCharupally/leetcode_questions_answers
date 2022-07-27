#include<iostream>

using namespace std;


void recursion(int &input, int &output) {
	if(input <=0) return;

	output = (output*10) +  (input % 10);
	input /= 10;

	recursion(input,  output);

	
}


int main() {
	int input = -123; //120;
	int output = 0;


	if(input <0) { 
		input *= -1; 
		recursion(input, output); 
		cout << (output*-1) << endl;
	}
	else { 
		recursion(input, output);
		cout << output << endl;
	}
	

}
