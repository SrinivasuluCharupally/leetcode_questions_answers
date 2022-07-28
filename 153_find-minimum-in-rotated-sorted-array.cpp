#include<iostream>
#include<vector>

using namespace std;

void recursion(vector<int> input, int &index, int &target, int &rotationsize, int &foundat) {
//	if(index >= 0) { cout << "Rotated by elements " << rotationsize << "  , found at : " << foundat << endl; return; }

//	if( input[index] >= input[index+1] && index+1 < input.size() ) { rotationsize = index+1; }

	if(input[index] > input[index-1] && index >= 0) { rotationsize +=1; 

	//if(target == input[index]) foundat = index;	
	
	index -= 1;
	recursion(input, index, target, rotationsize, foundat);
	}
}

int main() {
	vector<int> input = {4,5,6,7,1,2, 3};
	int target = 0, index = input.size()-1, rotationsize = 0, foundat=0;

	recursion(input, index, target, rotationsize, foundat);
	if(rotationsize < input.size()-1) cout << "No of rotations " << rotationsize+1 << ", lowest value " 
						<< input[input.size()-rotationsize-1] << endl;

}
