#include<iostream>
#include<vector>

using namespace std;

void recursion(vector<int> &input, int &index) {
	if(index <0) return;

	if(input[index] <9) {input[index] += 1; return; }
	else {
		if(input[index] == 9 && index == 0) { 
			input[index] = 0; 
			vector<int>::iterator itr;
			itr = input.begin();
			input.insert(itr,1);
			return;
		}
		input[index] = 0; index -= 1;
		recursion(input, index);
	}


}


int main() {
	vector<int> input = {9,9,9};
//	input.push_back(0);
//	vector<int> output ;
	int index = input.size()-1;
	recursion(input, index);

	for(int i =0; i < input.size(); i++)
		cout << input[i];
	cout << endl;
}
