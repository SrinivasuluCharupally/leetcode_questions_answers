#include<iostream>
#include<vector>


using namespace std;


void recursion(vector<int> input, int &start, int &mover, int &max ) {
	if( mover >= input.size() ) {
	      // 	if(start < input.size()- 1) {
		if(max > input[start] ) cout << max << " ";
		else cout << " -1 " ;
       //	}

		return;
	}
//	else  {	
	if(input[mover] > max) max = input[mover];
	mover += 1;
	cout << "starting 1 " << start << " " <<  mover << endl;
	recursion(input, start, mover, max);

	if(start < input.size() - 1) {
	start += 1;
	mover = start+1;
	max = input[start];
	cout << "      starting 2 "<< start << " " << mover << endl;
	recursion(input, start, mover, max);
	}
//	}
}

int main() {
	vector<int> input = {1,3,2, 4, 2, 1, 0 };
	cout << input.size() << endl;
	int start =0, mover = 1;
	int max = input[start];
	recursion(input, start, mover, max);

}
