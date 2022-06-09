#include<iostream>
#include<vector>

using namespace std;

void leftToright(int *input, int start, int end, vector<int> &lTor) {
	if(start > end) return;
	
		if(input[start-1] < input[start])
			lTor[start] = lTor[start-1] +1;

		leftToright(input, start+1, end, lTor);
	
}

void rightToleft(int *input, int start, int end, vector<int> &rTol) {
	if( end < start) return;
	
	if(input[end] > input[end+1])
			rTol[end] = rTol[end+1] + 1;

	rightToleft(input, start, end-1, rTol);
}

void max_function(vector<int> &lTor, vector<int> rTol, int start, int end, int &total) {
	if(start >end) return;

	cout << max(lTor[start], rTol[start]) << " " << lTor[start] << " " << rTol[start] << endl;

	total += max(lTor[start], rTol[start]);

	max_function(lTor, rTol, start+1, end, total);
}

int main() {
	int input[] = {1,0,2}; //{1,2,3,0};
	
	vector<int> lTor(3,1), rTol(3,1);
	leftToright(input, 1, 2, lTor);
	rightToleft(input, 0, 1, rTol);

	int total=0;
	max_function(lTor, rTol, 0, 2, total);
	cout << total << endl;

}
