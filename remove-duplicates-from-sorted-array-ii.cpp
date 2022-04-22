#include<iostream>
#include<vector>


using namespace std;

void recursion(vector<int> &input, int &size, int &index, int &position) {
	if(index >= input.size() || position >= input.size() ) { for(int i = 0; i < index; i++) cout << input[i] << " " ; return; }

	int occurance = 1;
	while(input[index] == input[position]) {
		occurance +=1;
		position += 1;
	}

	if(occurance >=2) {
		input[index] = input[index+1] = input[index];
		index += 2;
	}
	else {
		index += occurance;
	}

	input[index] = input[position];
	position += 1;

	recursion(input, size, index, position);
}

int main() {
	vector<int> input= {0,0,1,1,1,1,2,3,3}; //{0,0,1,1,1,2,2,3,3,4};

	int size = sizeof(input) / sizeof(int);
	int index = 0, position=1;
	recursion(input, size, index, position);

}
