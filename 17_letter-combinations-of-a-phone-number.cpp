#include<iostream>
#include<string>


using namespace std;


typedef enum {_, OO, abc, def, ghi, jkl, mno, pqrs, tuv, wxyz } in;

void recursion(string &input1, string &input2, int &offset, int &mover, string &output) {

	if(offset >= input1.size() || mover >= input2.size() ) return;


	output += input1.substr(offset, 1);
	output += input2.substr(mover, 1);
	cout << output << endl;

	mover += 1;
	output = "";
	recursion(input1, input2, offset, mover, output);
	
	offset += 1; mover = 0;
	recursion(input1, input2, offset, mover, output);
}

int main() {
	string input  = "23";
	int offset = 0, mover = 0;

	string getValue[] = {"_", "OO", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };	

// 	in value = abc ;
//	cout << getValue[value] << endl;


	string output;
	string x1 = input.substr(0,1);
	string value1 = getValue[stoi(x1) ]; //"abc";

	string x2 = input.substr(1,1);
	string value2 = getValue[stoi(x2)]; //"def";

	recursion(value1, value2, offset, mover, output);
}
