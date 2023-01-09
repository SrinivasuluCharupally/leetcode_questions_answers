#include<iostream>

typedef struct range {
	int start=0, stop=0;
} range;
int main() {
	int input[9] {-2,1,-3,4,-1,2,1,-5,4};
	int arraySize = sizeof(input) / sizeof(int);
	int sum = 0, previousSum = 0;
	int rangesize = 0;
	range currentRange{0,0}, previousrange{0,0};
	for(int index = 0; index < arraySize; index++) {
		sum += input[index] ; 
		currentRange.stop = index;
		if( sum > previousSum) {
			previousSum = sum;
			if(currentRange.stop - currentRange.start >= rangesize) { 
			       previousrange = currentRange;
			       rangesize = previousrange.stop - previousrange.start;
			}


		}
		if(sum <0) { 
			sum= 0 ;

			currentRange.start = index+1;
			
		}
	}
	printf(" max sum %d, start index %d, stop index %d  \n", previousSum , previousrange.start, previousrange.stop);

}

