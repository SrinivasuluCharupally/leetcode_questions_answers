#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void recursion(vector<int> input, int &missing, int &itr) {
	if(itr >= input.size()) return;

	if(input[itr] <= 0) {
		itr += 1;

	}
	else { 
		if(input[itr] != missing) { cout << "missing " << missing << endl; return; }
		else { itr += 1; missing +=1; }
	}

		recursion(input, missing, itr);
}

int main() {
	vector<int> input = {3,4,-1,1};

	int missing = 1, itr = 0;
	
	sort(input.begin(), input.end());
	recursion(input, missing, itr);
}
