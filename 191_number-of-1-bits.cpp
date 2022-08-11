#include<iostream>

using namespace std;

void recusion(int input,  int &noOfbits) {
	if(input > 0) {
		if(input & 1) {
			noOfbits += 1;
		}
		

		input = input >> 1;
		return recusion(input, noOfbits);
	}
	else return;
}


int main() {
	int input = 9;  // expected return value is 2
	int noOfbits = 0;
	recusion(input, noOfbits);
	printf("No of 1's in %d are : %u\n", input, noOfbits); 
}
