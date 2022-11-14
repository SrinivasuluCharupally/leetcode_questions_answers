#include<iostream>
#include<vector>
#include<map>

using namespace std;

void recursion(vector<int> input, int &start, map<int,int> &mymap) {
	if(start >= input.size()) { cout << "flase " << endl; return; }

	mymap[input[start]] += 1;
	if(mymap[input[start]] == 2) { cout << "duplicate number  " <<  input[start] << endl; return; }
	start += 1;
	recursion(input, start, mymap);
}


int main() {
	vector<int> input = {3,1,3,4,2};

	map<int, int> mymap;
	int start=0;
	recursion(input, start, mymap);



}
