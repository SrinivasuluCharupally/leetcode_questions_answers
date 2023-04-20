#include<iostream>

using namespace std;

double recursion(int n) {
	if(n<=1) return 1;

	return n*recursion(n-1);
}
int countZeros(int n, int &div, int &count) {
	if(n/div <= 0) return count;

	count += n/div;
	div *= 5;
	return countZeros(n, div, count);
}
int main() {
	cout << recursion(20) << endl;

	int div = 5, count=0;

	cout << countZeros(20, div, count) << endl;
}
