#include<iostream>

using namespace std;

typedef struct interval {
	int min, max;
} interval;


void recursion(interval input[4], int &index, interval newone) {
	if(index >=4) return;
	
	int tmp = input[index].min;

	if (input[index].max >= newone.min && input[index].min < newone.min)  { 
		index +=1;
		while(input[index].max >= newone.max && input[index].min <= newone.max) index +=1;
	        cout << "[" << tmp << "," << input[index-1].max << "]" << endl;

	}
	
	else { 
		cout << "[" << tmp << "," << input[index].max << "]" << endl; 

	index += 1; }

	recursion(input, index, newone);

	

}


int main() {
	interval input[4] = {{1,3},{4,6},{8,10},{15,18}};
	interval newone = {5,8};
//	interval output;
	int index = 0;
	recursion(input, index, newone);

}
