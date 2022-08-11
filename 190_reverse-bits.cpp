#include<iostream>

using namespace std;

void recusion(int input, unsigned int &result, int &noOfbits) {
	if(noOfbits > 0) {
		result = result << 1;
		if(input & 1) {
			result |= 1;
		}
		else result |= 0;

		input = input >> 1;
		noOfbits -= 1;
		return recusion(input, result, noOfbits);
	}
	else return;
}


int main() {
	int input = 43261596;  // expected return value is 964176192
        unsigned int result = 0;
	int noOfbits = 32;
	recusion(input, result, noOfbits);
	printf("reverse of  %d is %u\n", input, result); 
}
