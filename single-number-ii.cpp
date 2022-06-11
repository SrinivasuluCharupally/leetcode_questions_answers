#include<iostream>
#include<vector>
#include<map>

using namespace std;

void recursion(vector<int> input, int &start, map<int,int> &mymap) {
	if(start >= input.size()) return;

	mymap[input[start]] += 1;
	start += 1;
	recursion(input, start, mymap);
}


int main() {
	vector<int> input = {0,1,0,1,0,1,99};

	map<int, int> mymap;
	int start=0;
	recursion(input, start, mymap);

        for(map<int,int>::iterator itr = mymap.begin(); itr != mymap.end(); ++itr) {
                //      maxAliveyear = itr->first;
                        if(itr->second == 1) { 
				cout << "Missing one  is " << itr->first << endl;
			}
         }



}
