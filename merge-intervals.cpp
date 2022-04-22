#include<iostream>

using namespace std;

typedef struct interval {
	int min, max;
} interval;


void recursion(interval input[4], int &index) {
	if(index >=4) return;
	
	int tmp = input[index].min;

	for(; index<= 2 && (input[index].max >= input[index+1].min) ; ) {index += 1; }

	cout << "[" << tmp << "," << input[index].max << "]" << endl;

	index += 1;

	recursion(input, index);

	

}


int main() {
	interval input[4] = {{1,3},{2,6},{8,10},{15,18}};

//	interval output;
	int index = 0;
	recursion(input, index);

}
