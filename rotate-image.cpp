#include<iostream>

using namespace std;


void recursion(int input[][4], int output[][4], int &i, int &j) {
	if(i >= 4 || j >= 4) { 
//		for(int k = 0; k <4; k++) { 
//			for(int l = 0; l < 4; l++) 
//				cout << output[k][l] << " " ;
//			cout << endl;
//		}
		return;
	}

	output[j][(3-i)] = input[i][j];
	j += 1;
	recursion(input, output, i, j);

	i += 1;
	j = 0;
	recursion(input, output, i, j);


// 0,0 -> 0,3
// 0,1 -> 1,3
// 0,2 -> 2,3
//
// 1,0 -> 0,2
//
// 2,0 -> 0,1
//
// 3,0 -> 0,0

}

int main() {
	int input[4][4] = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};

	int output[4][4];

	int i=0, j=0;
	recursion(input, output, i, j);

		for(int k = 0; k <4; k++) { 
			for(int l = 0; l < 4; l++) 
				cout << output[k][l] << " " ;
			cout << endl;
		}
}



