#include<iostream>
#include<vector>

using namespace std;

typedef struct range {
	int min = -1;
	int max = -1;
} range;

void recursion(vector<int> input, int target, range &myrange, int &index) {
	if(index >= input.size()) return;

	//if(input[index] == target) { 
	//	myrange.min = index; 
	//	index +=1;
	while(input[index] == target ) {
		if(myrange.min == -1) myrange.min = index;
		index += 1;
	}
	if(myrange.min != -1) {myrange.max = index-1; return; }
	index +=1;
	recursion(input, target, myrange, index);

}


int main() {
	vector<int> input = {5,7,7,8,8,8,8,9,10};
	range myrange;
	int target = 8, index = 0;
	recursion(input, target, myrange, index);
	cout << myrange.min << " " << myrange.max << endl;
}

