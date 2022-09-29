#include<iostream>
#include<vector>


using namespace std;


void recursionProduct(vector<int> input, int &product, int &noOfZeros) {
	static int index=0;
	if(index >= input.size()) return;

	if(input[index] == 0) { 
		index += 1;
		if(noOfZeros >1) { noOfZeros += 1; return; }
		noOfZeros += 1;
                recursionProduct(input, product, noOfZeros);
	}
	else {
		product *= input[index];
		index += 1;
		recursionProduct(input, product, noOfZeros);
	}
}


int main() {
	vector<int> input = {-1,1,0,-3,3};

	int product=1, noOfZeros=0;
	recursionProduct(input, product, noOfZeros);

	for(int i =0; i < input.size(); i++) {
		if(noOfZeros == 2)
		       cout << "0" << " ";
		else if(noOfZeros == 1 && input[i] != 0) 
			cout << "0"  << " ";
		else if(noOfZeros == 1 && input[i] == 0)
			cout << product << " ";
		else cout << product / input[i] << " " ;
	}	
}
