#include<iostream>
#include<vector>


using namespace std;

void recursion(vector<int> &input, int &size, int &index, int &position) {
	if(index >= input.size() || position >= input.size() ) { for(int i = 0; i < index+1; i++) cout << input[i] << " " ; return; }

	int tmp = input[index];
	while(tmp == input[position]) { input[position] = -1; position++; } 
	index += 1;
	input[index] = input[position]; input[position] = -1; 
	position += 1;
	recursion(input, size, index, position);
}

int main() {
	vector<int> input= {0,0,1,1,1,2,2,3,3,4};

	int size = sizeof(input) / sizeof(int);
	int index = 0, position=1;
	recursion(input, size, index, position);

}
