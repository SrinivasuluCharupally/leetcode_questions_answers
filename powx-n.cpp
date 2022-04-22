#include<iostream>

using namespace std;

void recursion(double input, int &n, double &output) {
	if(n<1) return;

	output = output*input;
	n -= 1;
	recursion(input, n, output);
}

int main() {
	double input = 2.100, output = 1;
	int n = -3;
	int x = abs(n);

	recursion(input, x, output);

	if(n<0) cout << 1/output << endl;
	else cout << output << endl;
}
