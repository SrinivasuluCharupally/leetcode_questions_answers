#include<iostream>
#include<string>

using namespace std;


void recursion(string input, int &index, int &opened, int &closed, int &localmax, int &longpossible) {
	if(index >= input.size()) { cout << "Longest count =  " << longpossible << endl; return; }

	
	if((int)input[index] == 40) opened +=1;
	else if(opened > 0 && (int)input[index] == 41 ) {opened = opened - 1; localmax +=1; }
	else { opened = 0; longpossible = max(longpossible, localmax); localmax=0; }
	
	index +=1;
	recursion( input, index, opened, closed, localmax, longpossible);
}



int main() {
	string input = ")()())";

	printf("%d , %d " , input[1], input[0]);
	int index = 0, opened=0, closed=0, localmax=0, longpossible=0;
	recursion(input, index, opened, closed, localmax, longpossible);
}
