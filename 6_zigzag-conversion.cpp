#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

void recursion(string input, int &index, string &output, int charInLine) {
	if(index >= charInLine) return;

	int tmp = index;
	while(tmp <= input.size()) {
		output += input[tmp];
		tmp += charInLine;
	}

	index += 1;

	recursion(input, index, output, charInLine);
}


int main() {
	string input = "PAYPALISHIRING";
	double rows = 3;

	double charInLine = ceil(input.size() / rows);

	cout << charInLine << " " << input.size() << endl;
	int index = 0;
	string output = "";
	recursion(input, index, output, charInLine);
	cout << output << endl;
}
