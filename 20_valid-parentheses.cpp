#include<iostream>
#include<string>

using namespace std;


void recursion(string input, int &index) {
	if(index >= input.size()) { cout << "True " << endl; return; }
	
	
	if((int)input[index] == ((int)input[index+1] -1) ||  (int)input[index] == ((int)input[index+1] -2) )  { index += 2; }
	else { cout << "False , Not matching " << endl; return; }

	recursion( input, index);
}

int main() {
	string input = "()[]{}";

//	printf("%d" , input[1]);
	int index = 0;
	recursion(input, index);
}
