#include<iostream>

using namespace std;


void recursion(int a[][4], int b[][4], int &i, int &j, int &k, int &pixel_val) {
	if(i >=3 || j >= 4 || k >= 4) { 
		if(j==4) cout << pixel_val << " " ; 
		return; }

	pixel_val += a[i][j] * b[j][k];

	j += 1;
	recursion(a, b, i, j, k, pixel_val);
	j = 0; k += 1, pixel_val = 0;
	recursion(a,b,i,j,k, pixel_val);
	i +=1; j = 0; k=0; cout << endl;
	recursion(a,b,i,j,k, pixel_val);


}

void rotation(int b[][4], int &i , int &j, int &offset) {
	if(i >= 4 || j >= 4) { return; }

	cout << b[j][offset] << " " ;
	
	j += 1; 
	rotation(b,i,j,offset);
	i +=1; j = 0; offset += 1;
	
	rotation(b,i,j,offset);
}


int main() {
	int a[3][4] = {
			{1,2,3,4},
			{1,2,3,4},
			{1,2,3,4}
			};

	int b[4][4] = {
			{1,2,3,4},
			{1,2,3,4},
			{1,2,3,4},
			{1,2,3,4}
			};
	int pixel_val = 0, i = 0, j= 0, k = 0;
	recursion(a,b, i, j, k, pixel_val);

	i = 0; j = 0;
	int offset = 0;
	int c[4][4];
	rotation(b, i, j, offset);
}
