#include<iostream>
#include<string>

using namespace std;

void recursion(string input, string find, int &index) {
	if(index >= input.size()) return;

	string tmp = input.substr(index, find.size());
	if(tmp == find) { cout << "Found at index " << index << endl; return; }

	index += 1;
	recursion(input, find, index);
}


int main() {
	string input = "helello";
	string find = "ll";
	int index = 0;

	recursion(input, find, index);
}
