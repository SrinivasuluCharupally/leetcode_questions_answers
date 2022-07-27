
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int TripleStep(int n, int array[]) {
	if(n < 0) return 0;
	if(n == 0) return 1;
	else if(array[n] > -1) return array[n];
	else {
		array[n] = TripleStep(n-1, array) + TripleStep(n-2, array); //+ TripleStep(n-3, array);
		return array[n];
	}

}

int main() {
	int n = 4;
	int array[n+1];
        memset(array, -1, sizeof(array)) ;
	int result = TripleStep(n, array);
	cout << " Total count = " << result << endl;
}


