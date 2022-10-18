//https://tenderleo.gitbooks.io/leetcode-solutions-/content/GoogleEasy/246.html
//

#include<iostream>
#include<map>
#include<vector>

using namespace std;

bool recusrion(string input, map<int, int> mymap) {
	static int startIndex = 0, endIndex = input.size()-1;
	static map<int, int>::iterator itr;

	if(startIndex >= endIndex ) return true;

	itr = mymap.find( ((int)input[startIndex]) - 48);

	if(itr->second  == (int)input[endIndex] - 48 ) {
		startIndex ++; endIndex--;
		recusrion(input, mymap); }
	else 
		return false;

}


int main() {
	map<int, int> mymap = {{0,0}, {1,1}, {8, 8}, {6,9}, {9,6}};

	string input = "69";

	if(recusrion(input, mymap)) cout << "strobogrammatic number " << endl; 
}
