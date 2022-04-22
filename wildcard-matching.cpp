#include<iostream>
#include<string>

using namespace std;

void recursion(string input, string expresion, int &index, char &precedingChar) {
	if(index >= input.size()) return;

	if(input.compare( index, 1, expresion, index, 1) == 0 )   { precedingChar = input[index]; index += 1; }
	else if(expresion.compare(index, 1, "?") == 0 ) { precedingChar = input[index]; index += 1; } 
	else if(expresion.compare(index, 1, "*") == 0 ) { cout << "True" << endl; return ;}
	else { cout << "Flase " << endl; return ; }

	recursion(input, expresion, index, precedingChar);

}


int main() {
	string input = "ab";
	string expresion = "?*";

	int index = 0;

	char precedingChar;


	recursion(input, expresion, index, precedingChar);

	input = "aba";
	expresion = "a?*";
	index = 0;
	recursion(input, expresion, index, precedingChar);

}	

