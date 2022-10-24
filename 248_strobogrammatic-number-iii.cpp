//https://tenderleo.gitbooks.io/leetcode-solutions-/content/GoogleEasy/248.html
//

#include<iostream>
#include<map>
#include<vector>
#include<string>


using namespace std;

bool recusrion(string input, map<int, int> mymap, int startIndex, int endIndex) {
//	static int startIndex = 0, endIndex = input.size()-1;
	static map<int, int>::iterator itr;

	if(startIndex >= endIndex ) return true;
	
	itr = mymap.find( ((int)input[startIndex]) - 48);
	if(itr == mymap.end()) return false;

	if(itr->second  == (int)input[endIndex] - 48 ) {
		startIndex ++; endIndex--;
		recusrion(input, mymap, startIndex, endIndex); }
	else { 
		return false;
	}

}


int main() {
	map<int, int> mymap = {{0,0}, {1,1}, {8, 8}, {6,9}, {9,6}};

	int low = 51, high = 100;
	string input;
	for(int i = low; i <= 100; i++) {
		int startIndex=0, endIndex=input.size()-1;
		input = to_string(i);
	        if(recusrion(input, mymap, startIndex, endIndex)) { cout << "strobogrammatic number "  << input << endl;  }
	}



}
