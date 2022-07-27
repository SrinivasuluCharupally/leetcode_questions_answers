#include<iostream>
#include<vector>

using namespace std;

void recursion(vector<int> input, int &index, int &target, int &rotationsize, int &foundat) {
	if(index >= input.size()) { cout << "Rotated by elements " << rotationsize << "  , found at : " << foundat << endl; return; }

	if( input[index] >= input[index+1] && index+1 < input.size() ) { rotationsize = index+1; }

	if(target == input[index]) foundat = index;	
	
	index += 1;
	recursion(input, index, target, rotationsize, foundat);
}

int main() {
	vector<int> input = {4,5,6,7,0,1,2};
	int target = 0, index = 0, rotationsize = 0, foundat=0;

	recursion(input, index, target, rotationsize, foundat);

}
