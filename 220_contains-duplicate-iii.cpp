#include<iostream>
#include<vector>
#include<map>

using namespace std;

void recursion(vector<int> input, int &start, map<int, vector<int>> &mymap) {
	if(start >= input.size()) { return; }

	mymap[input[start]].push_back(start);
	start += 1;
	recursion(input, start, mymap);
}


int main() {
	vector<int> input = {1,2,3,1,2,3}; //{4,1,2,1,2};

	map<int, vector<int>> mymap;
	int start=0;
	int indedDiff = 2, valueDiff=3;
	recursion(input, start, mymap);

        for(map<int, vector<int>>::iterator itr = mymap.begin(); itr != mymap.end(); ++itr) {
//                //      maxAliveyear = itr->first;
                        if((itr->second).size() >= 2) { 
				vector<int> tmp = itr->second;
				for(int i = 0; i < tmp.size(); i++) {
					if( (abs(tmp[i] - tmp[i+1]) <= indedDiff)  && (input[tmp[i]] - input[tmp[i+1]] <= valueDiff) ) {
						
						cout << " true " << tmp[i]  << tmp[i+1]  << endl;
						return 0;
					}

		         	}
                       }
//
	}
	cout << "false " << endl;
}
