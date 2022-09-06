#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n) {

	for(int i = 2; i <= sqrt(n); i++)
		if(n % i == 0) { cout << n << " not a prime" << endl; return 0 ; }
	cout << n << " is Prime" << endl;
	return 1;
}


void recursion(int input, int &count) {
	if(input <2) { cout << "total prime count " << count << endl; return; }

	if(isPrime(input)) count += 1;
	recursion(input-1, count);
}

int main() {
	int input = 10;
	int count = 0;
	recursion(input, count);
}
