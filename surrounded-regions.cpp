// reference : https://www.geeksforgeeks.org/traverse-a-given-matrix-using-recursion/
//

#include<iostream>
#include<vector>

using namespace std;


void recursion2(vector<vector<int>> &input, int x, int y, int targetSearch) {


	if(x >= 3 ) return;
	if(y >= 3 ) return;

	if(input[x][y] == targetSearch) {
		input[x][y]=1;	
		//printf("\nfound the element, x=%d , y=%d ", x,y);
		//	cout << endl;
		//	return;
	}

	recursion2(input, x, y+1, targetSearch);
	recursion2(input, x+1, 0, targetSearch);
		
}

int main() {
	vector<vector<int>> input = {{1, 1, 1, 1},
			  {1, 0, 0, 1},
			  {1, 1, 0, 1},
			  {1, 0, 1, 1}} ;

	for(int i =0; i < 4; i++) {
		for(int j=0; j < 4; j++)
			printf("%d  ", input[i][j]);
		printf("\n");
	}

	int x =1, y=1, targetSearch=0;

	recursion2(input, x, y, targetSearch);
	for(int i =0; i < 4; i++) {
		for(int j=0; j < 4; j++)
			printf("%d  ", input[i][j]);
		printf("\n");
	}
}
