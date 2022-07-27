#include<iostream>
#include<string>

using namespace std;


void recursion(string input, int index, int &columnNumber) {

	if(index < 0) { cout << columnNumber << endl; return; }

	int x = input[index]-64;
	columnNumber = columnNumber + (x*26) ;

	cout << x << " " << columnNumber << endl;
	index -= 1;

	recursion(input, index, columnNumber);

//	printf("%c" , (columnNumber / 26) + 64);
//	printf("%c" , (columnNumber % 26) + 65);
//	printf("\t --> %d \n", columnNumber);
//
//	recursion(columnNumber+1,  requiredColoms);

}


int main() {
	string input = "ZY";

	int index=input.size()-1, columnNumber=0;
//	int requiredColoms = 201;

	recursion(input, index, columnNumber);
}
