#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void recursion(vector<int> input, int &start, int &mover, int target) {
	if( mover >= input.size() || start >= input.size() ) return;

	if(input[start] + input[mover] == target) { cout << start << " " << mover << endl; return; }
	
	mover +=1;                  recursion(input, start, mover, target); 
	start +=1; mover = start+1; recursion(input, start, mover, target);

}


int main() {
	vector<int> input = {3,2,4};
	int target = 6;
	int start = 0, mover = 1;
//	sort(input.begin(), input.mover());

	recursion(input, start, mover, target);

}
