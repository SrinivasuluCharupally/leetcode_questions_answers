#include<iostream>
#include<string>

using namespace std;

void recursion(string input, int &index, string &tmp, string &output) {
	if(index > input.size()-1) {tmp += " "; tmp += output; output = tmp; cout << output << endl ; return; }

	if(input.compare(index,1, " ") == 0 ) { tmp += " "; tmp += output; output = tmp;  tmp = ""; }
	else tmp += input[index];

	index += 1;
	recursion(input, index, tmp, output);

}


int main() {
	string input = "the man is nice";
	string output;

	int index = 0; //input.size()-1;
	string tmp;

	recursion(input, index, tmp, output);
}
