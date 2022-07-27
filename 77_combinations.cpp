#include<iostream>
#include<vector>

using namespace std;

void recursion(int &n, int &k, int &local) {
	if(n < 0 || local <1)  return;

	cout << "[" << local << "," << n << "]" << endl;
	local -= 1;
	recursion(n, k, local);
	n -= 1;
	local = n-1;
	recursion(n, k, local);
}


int main() {
	int n = 4, k = 2;
	int local = n-1;
	recursion(n,k, local);
}
