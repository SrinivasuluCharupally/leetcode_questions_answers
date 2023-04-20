#include<iostream>
#include<vector>


using namespace std;


void recursion( vector<int> input, int start, int end, int &tmpsum, vector<int> &tmparray, vector<vector<int>> &results){


    if(tmpsum >= 8) {
	if(tmpsum == 8) {
		results.push_back(tmparray);
		//return;
	}
	return;
    }

    if(start >= end) return;

	tmpsum += input[start];
	tmparray.push_back(input[start]);


	recursion(input, start, end, tmpsum, tmparray, results);

	tmpsum -= tmparray[tmparray.size()-1];
	tmparray.pop_back();

	recursion(input, start+1, end, tmpsum, tmparray, results);


}


int main(){
	vector<int> input = {1,2,3,4,5};
	int sum = 8, tmpsum=0;

	int start = 0, end = input.size();
	vector<vector<int>> results;
	vector<int> tmparray;
	recursion(input, start, end, tmpsum, tmparray, results);

	for(int i =0; i < results.size(); i++) {
		for(int j = 0; j < results[i].size(); ++j) {
			cout << results[i][j] << " " << endl;
		}
		cout << endl;
	}
}
