#include<iostream>
#include<vector>

using namespace std;

void recursion(vector<int> input, int &Index, int &evenTotal, int &oddTotal) {
	if(Index >= input.size() ) return;

	if(Index % 2 ) evenTotal += input[Index];
	else oddTotal += input[Index];

	Index += 1;

	recursion(input, Index, evenTotal, oddTotal);
}

int main() {
	vector<int> input = {2,7,9,3,1};

	int Index=0;
	int evenTotal=0, oddTotal=0;
	recursion(input, Index, evenTotal, oddTotal);
	if(evenTotal > oddTotal) cout << evenTotal << endl;
	else cout << oddTotal << endl;
}
