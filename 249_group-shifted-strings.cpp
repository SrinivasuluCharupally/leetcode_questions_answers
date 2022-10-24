#include<iostream>
#include<map>
#include<vector>

using namespace std;

void recursion(vector<string> input, map<int, vector<string>> &mymap) {
	static int index = 0;
	if(index >= input.size()-1) return;
	
	map<int, vector<string>>::iterator itr;
	itr = mymap.find(input[index].size());

	if( itr != mymap.end() ) itr->second.push_back(input[index]);
	else mymap[input[index].size()].push_back(input[index]) ;

	index++;
	recursion(input, mymap);

}


int main() { 
	vector<string> input = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};

	map<int, vector<string>> mymap;
	recursion(input, mymap);

	map<int, vector<string>>::iterator itr;
	for(itr = mymap.begin() ; itr !=  mymap.end(); ++itr) {
		for(int i = 0 ; i < itr->second.size(); i++) 
			cout << itr->second[i] << " "; 

		cout << endl;
	}
}
