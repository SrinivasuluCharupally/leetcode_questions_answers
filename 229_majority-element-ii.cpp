#include<iostream>
#include<vector>
#include<map>

using namespace std;


void recursion(vector<int> input, map<int,int> &mymap) {
	static int index = 0;
	if(index >= input.size() )  return;
	
	mymap[input[index]] += 1;
	index += 1;
	recursion(input, mymap);
	
}


int main() {
	vector<int> input = {3,2,3};
	int div = 3;
	map<int, int> mymap;
	recursion(input, mymap);

	for(map<int, int>::iterator itr = mymap.begin(); itr != mymap.end(); ++itr) {
		if(itr->second > input.size() / div) 
			cout << itr->first << ", occured times :  " << itr->second << endl;
	}


}
