// reference : https://www.geeksforgeeks.org/traverse-a-given-matrix-using-recursion/
//

#include<iostream>
#include<vector>

using namespace std;


void recursion2(int input[][4], int x, int y, int celebraty) {


	if(x >= 4 ) return;
	if(y >= 4) { 
		if(celebraty) { cout << "Celebraty id = " << x << endl; }
	//	celebraty = false; 
		return; }

	if(input[x][y] == 1) {
//			printf("\nt, x=%d , y=%d ", x,y);
//			cout << endl;
		celebraty=false;
			return;
	}

	//else if(input[x][y] <= celebraty && input[x+1][y] >= celebraty) {	
	recursion2(input, x, y+1, celebraty);
//	}
	celebraty=true;
	recursion2(input, x+1, 0, celebraty);
		
}

int main() {
	int input[][4] = { {0,0,1,0},
			  {0,0,1,0},
			  {0,0,0,0},
			  {0,0,1,0}};

	for(int i =0; i < 4; i++) {
		for(int j=0; j < 4; j++)
			printf("%d  ", input[i][j]);
		printf("\n");
	}

	int x =0, y=0;
	bool celebraty=true;

	recursion2(input, x, y, celebraty);
}
