#include<iostream>
#include<string>

using namespace std;

void recursion( string input, int &start, int &end) {
	if(start >= end ) { cout << "Is Palindrom " << endl; return; }

	if(input[start] == input[end]) {
		start += 1; end -= 1;
		return recursion(input, start, end);
	}
	else { cout << "Not a Palindrom" << endl; return;}
}

int main() {
	string input = "ababa";
	//bool check[
	int start = 0, end = input.size()-1;
	recursion(input, start, end);
	string input1 = "abaca";
	start = 0; end = input1.size()-1;	
	recursion(input1, start, end);

}
