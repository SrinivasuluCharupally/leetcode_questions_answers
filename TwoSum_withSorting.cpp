#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void recursion(vector<int> input, int &start, int &end, int target) {
	if(start >= end) return;

	if(input[start] + input[end] == target) { cout << start << " " << end << endl; return; }
	else if (input[start] + input[end] < target) { start +=1; recursion(input, start, end, target); }
	else if (input[start] + input[end] > target) { end +=1; recursion(input, start, end, target); }
}


int main() {
	vector<int> input = {3,2,4};
	int target = 6;
	int start = 0, end = input.size()-1;
	sort(input.begin(), input.end());

	recursion(input, start, end, target);

}
