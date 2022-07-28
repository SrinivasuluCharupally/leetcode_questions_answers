#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void printing(vector<int> input, int index, int low, int high) {
	
	int mover = low;
	while(mover <= high) {
		if(input[index] == mover) { mover += 1; index +=1;  }
		else { cout << mover << endl;
		       mover += 1;
		}
	}


}


void recursion(vector<int> input, int start, int end, int low, int high) {
	if(start > end) return;
	
	int mid = (start+end)/2;
	if(input[mid] == low) { cout << "Found" << endl; return; }
	else { if(input[mid] < low && input[mid+1] > low) {cout << "Index Found at " << mid+1 << endl; printing(input, mid+1, low, high); return; } }
	if(input[mid] < low) recursion(input, mid+1, end, low, high);
	else recursion(input, start, mid-1, low, high);
}

int main() {
	vector<int> input = {1, 14, 11, 51, 15}; // { 1, 11, 14, 15, 51 };
	sort(input.begin(), input.end());
	//input.sort();

	int low = 50, high = 55, start=0, end=input.size()-1;

	recursion(input, start, end, low, high);
}
