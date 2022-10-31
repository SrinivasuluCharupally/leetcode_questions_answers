#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

void recursion(vector<int> input, int &start, int &count) {
	if(start >= input.size()) return;

//	mymap[input[start]] += 1;
	if(input[start] == input[start+1]) start += 2;
	else { cout << input[start] << endl; 
		start += 1; count += 1; }

	recursion(input, start, count);
}


int main() {
	vector<int> input = {1,2,1,3,2,5};

	int start=0, count = 0;
	sort(input.begin(), input.end());

	recursion(input, start, count);


//        for(map<int,int>::iterator itr = mymap.begin(); itr != mymap.end(); ++itr) {
//                //      maxAliveyear = itr->first;
//                        if(itr->second != 2) { 
//				cout << "Missing one  is " << itr->first << endl;
//			}
//         }
//


}
