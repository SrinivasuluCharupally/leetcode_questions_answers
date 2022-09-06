#include<iostream>
#include<vector>

using namespace std;

void recursion(vector<int> input, int &even, int &odd, int index) {
	if(index >= input.size()) { if(even > odd ) cout << even; 
				    else cout << odd;
				    return;
	}

	if(index %2 ) even += input[index];
	else odd += input[index];

	index += 1;
	recursion(input, even, odd, index);

}

int main() {
	vector<int> input = {1,2,3,1};

	int index = 0, odd = 0, even = 0;

	recursion(input, even, odd, index) ;

}
