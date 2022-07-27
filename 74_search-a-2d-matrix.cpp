// reference : https://www.geeksforgeeks.org/traverse-a-given-matrix-using-recursion/
//

#include<iostream>
#include<vector>

using namespace std;


void recursion2(int input[][4], int x, int y, int targetSearch) {


	if(x >= 3 ) return;
	if(y >= 4) return;

	if(input[x][y] == targetSearch) {
			printf("\nfound the element, x=%d , y=%d ", x,y);
			cout << endl;
			return;
	}

	else if(input[x][y] <= targetSearch && input[x+1][y] >= targetSearch) {	
		recursion2(input, x, y+1, targetSearch);
	}
	else recursion2(input, x+1, 0, targetSearch);
		
}

int main() {
	int input[][4] = { {1,   3,  5,  7},
			  {10, 11, 16, 20},
			  {23, 30, 34, 50}};

	for(int i =0; i < 3; i++) {
		for(int j=0; j < 4; j++)
			printf("%d  ", input[i][j]);
		printf("\n");
	}

	int x =0, y=0, targetSearch=16;

	recursion2(input, x, y, targetSearch);
}
