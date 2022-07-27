// we are not using merging of two arrays.

#include<iostream>
#include<vector>

using namespace std;


void recursion(vector<int> A, vector<int> B, int &bigArray, int smallArray, int &mean) {
	if(bigArray >= A.size() && bigArray >= B.size()) { mean /= (A.size() + B.size()); return; }

	if(bigArray <= smallArray) mean += A[bigArray] + B[bigArray];
	else if(bigArray == A.size()) mean += A[bigArray];
	else mean += B[bigArray];

	bigArray += 1;
	recursion(A, B, bigArray, smallArray, mean);

}


int main() {
	vector<int> A = {1,2, 5};
	vector<int> B = { 3,4};

	int bigArray = 0; //A.size() > B.size() ? A.size() : B.size();
	int smallArray = A.size() <= B.size() ? A.size() : B.size();
	int  mean=0;
	recursion(A,B,bigArray, smallArray, mean);
	cout << mean << endl;
}

