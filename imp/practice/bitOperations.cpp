#include<iostream>

using namespace std;


int main(){
	int input = 12;
	
	int count = 0;
	while( input >0 ) {
		if(input & 1) count++;
		input = input>>1;
	}
	cout << count << endl;
}
