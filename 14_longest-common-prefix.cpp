#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<limits>
#include <bits/stdc++.h>


using namespace std;

void recursion(vector<string> input, int &index, string &output, int  smallIndex, string &finaloutput) {
	if(index >= smallIndex) return;
	
	output += input[0].substr(index, 1);

	int i = 0;
	while( ( i < input.size()) && (! input[i].compare(0,index+1, output))) {
		i++; 
	}
	if(i == 3) finaloutput = output;
	index += 1;
	recursion(input, index, output, smallIndex, finaloutput);

}


int main() {
	vector<string> input = {"flower","flow","flight"};

	int index = 0;

	string output, finaloutput;

	int smallIndex=INT_MAX;

	for(int i = 0; i < input.size() ; i++) {
		int x = input[i].size();
		smallIndex = min(smallIndex, x);
	}
		
	
	recursion(input, index, output, smallIndex, finaloutput);
	cout << finaloutput << endl;

}
