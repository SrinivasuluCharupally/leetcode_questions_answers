// reference : https://www.geeksforgeeks.org/traverse-a-given-matrix-using-recursion/
//

#include<iostream>
#include<vector>

using namespace std;


void recursion2(int input[][5], int x, int y, int targetSearch, int &height , int &width) {


	if(x >= height || y >= width ) return;

	if(input[x][y+1] == 0 ) {
		width = y+1;
	}

	else if(input[x+1][y] == 0) {
		height = x+1;
	}


	
	recursion2(input, x, y+1, targetSearch, height, width);
	recursion2(input, x+1, y, targetSearch, height, width);
	
}




int main() {
	int input[][5] = { {1,0,1,0,0},
			   {1,0,1,1,1},
			   {1,1,1,1,1}, 
			   {1,0,0,1,0} };

       			/*{ {1,   3,  5,  7},
			  {10, 11, 16, 20},
			  {23, 30, 34, 50}};
			  */

	for(int i =0; i < 4; i++) {
		for(int j=0; j < 5; j++)
			printf("%d " , input[i][j]);
		printf("\n");
	}

	int x =0, y=0, targetSearch=16, height=4, width=5;
	
	int size = 0;
	
	for(int i =0; i < 4; i++) {
		for(int j=0; j < 5; j++) {
			x = i; y = j; height=4, width=5;
			if(input[x][y] !=0) {
				recursion2(input, x, y, targetSearch, height, width );
				size = max(size,(height-i) * (width-j) );
				cout << height << " " << width <<  "  size = " << (height-i) * (width-j) << endl;
			}
		}
	}
	cout << "Max rectangle size = " << size << endl;
}
