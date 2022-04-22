#include<iostream>
#include<vector>

using namespace std;

void recursion(vector<int> input, int target, int left, int right) {
	if(left >= right) return;

	int mid = (left + right )/2; 
	if(input[mid] == target) { cout << "Found at index : " << mid << endl; return; }
	else if(left+1 == right) { cout << "Found inserting range " << left << " " << right << endl; return; }
	
	if(input[mid] >= target) recursion(input, target, left, mid);
	else recursion(input, target,  mid, right);
}


int main() {
	vector<int> input = {1, 3, 5, 6, 7, 8, 9};
	int target = 4;

	int left =0, right = input.size(), mid = 0;

	recursion(input, target, left, right);

}
