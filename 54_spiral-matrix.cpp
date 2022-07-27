#include<iostream>


static int iR =0, jR=0;
static int sizeR = 4, sidesR=0;
static bool forwardR = true, downwardsR=false, backwardsR=false, upwardsR=false;
static int aR=0;


void spiralOrderWithRecursion(int input[][4]) {

	if(sidesR > (2*4)-1)  return;
	else {

		if(forwardR) {
			for( int l =jR; l < sizeR-aR; l++) {
				printf(" %d ", input[iR][l]);
				jR = l;
			}
			forwardR = false; downwardsR = true;
		}
		else if(downwardsR) {
			for(int l =iR+1; l < sizeR-aR; l++) {
				printf(" %d ", input[l][jR]);
				iR=l;
			}
			downwardsR = false; backwardsR=true;
		}
		else if(backwardsR) { 
			for( int l=jR-1; l >= 0+aR; l--) {
				printf(" %d ", input[iR][l]);
				jR=l;
			}
			backwardsR=false; upwardsR=true;
		}
		else if(upwardsR) {
			for(int  l=iR-1; l > 0+aR; l--) {

				printf(" %d ", input[l][jR]);
				iR=l; //j=l;
			}
			jR=iR;
			upwardsR=false; forwardR=true;
			aR++;
		}
		//a++;
//		}
	sidesR = sidesR+1;
	spiralOrderWithRecursion(input);
	}
}




int main() {
	int input[][4] = 	{ {1, 2, 3, 4},
				  {12,13,14,5},
				  {11,16,15,6},
				  {10,9, 8, 7}};
	for(int i = 0; i < 4; i++) {
	       printf("\n");	
		for(int j=0; j < 4; j++) {
			printf(" %d\t",  input[i][j]);
		}
	}
	//x=0; y=0;

	printf(" \n Spiral with recursion \n");
	spiralOrderWithRecursion(input);
	
	printf(" \n ");
}

