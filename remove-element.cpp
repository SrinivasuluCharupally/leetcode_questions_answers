#include<iostream>
#include<vector>


using namespace std;

void recursion(vector<int> &input, int &size, int &index, int &position, int element) {
	if(index >= input.size() || position >= input.size() ) { for(int i = 0; i < index; i++) cout << input[i] << " " ; return; }

	int tmp = input[position];
	if(tmp != element  ) { input[index] = input[position] ; index += 1; position += 1;  }
	else { position +=1; }

//	input[index] = input[position]; 
//	position += 1;
	recursion(input, size, index, position, element);
}

int main() {
	vector<int> input= {0,1,2,2,3,0,4,2};

	int size = sizeof(input) / sizeof(int);
	int index = 0, position=0, element=2;
	recursion(input, size, index, position, element);

}
