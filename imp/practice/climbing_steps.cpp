#include<iostream>
#include<vector>


using namespace std;

int recursion( int n, int array[]) {
	if(n < 0) return 0;
	if( n == 0 ) return 1;

	if(array[n] != -1) return array[n];

	else return array[n] = recursion(n-1, array) + recursion(n-2, array) ;
}

int main() {
	int n = 4;

	int array[n+1] = {-1,-1,-1,-1, -1};

	cout << recursion(n, array) << endl;
}
