#include<iostream>
using namespace std;

void recursionMatrix(int input[][5], int x, int y, int & blockSize) {
	if(y<0 || x <0 ) { cout << endl << "Max block size " << blockSize << endl; return; }

	else {
		if( input[x][y] ==1) {
			int i = x, j = y;
			int xsize = 0, ysize = 0;

			while(input[i][j] ==1 && j >= 0) {

				j = y;	
				while(input[i][j] ==1 && j >= 0) {
					j -= 1;
					xsize += 1;
				}
				i -= 1;
				ysize += 1;
			}
			
			int block = ysize > xsize ? xsize : ysize;
			blockSize = (blockSize < block * block) ? (block * block) : blockSize ;
		}
		else {

			recursionMatrix(input, x-1,y, blockSize);
			recursionMatrix(input, x, y-1, blockSize);
			return;
		}
	}
}

int main() {
	int input[][5] =  {{1,0,1,0,0},
		           {1,0,1,1,1},
			   {1,1,1,1,1},
			   {1,0,0,1,0}}; // find max block of '1', i.e 2x2 = 4
	for(int i = 0; i < 4; i++) {
	       printf("\n");	
		for(int j=0; j < 5; j++) {
			printf(" %d ",  input[i][j]);
		}
	}
	int blockSize = 0;

	recursionMatrix(input, 4,5, blockSize);


}

