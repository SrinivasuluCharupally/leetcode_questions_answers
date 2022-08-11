#include<iostream>
#include<vector>

using namespace std;


void recursion(vector<int> &input, int &index, int rotationSteps) {
	if(rotationSteps <= 0 ) return;

	int tmp = input[input.size()-1];
	input.erase(input.begin() + input.size()-1);

	input.insert(input.begin(), tmp);

	rotationSteps -= 1;
	recursion(input, index, rotationSteps);
}


int main() {
	vector<int> input = {1,2,3,4,5,6,7};
	int rotationSteps = 3;
	int index = 0;
	recursion(input, index, rotationSteps);
	for(int i = 0; i < input.size(); i++) cout << input[i] << " " ;
	cout << endl;
}
