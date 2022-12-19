#include<iostream>
using namespace std;

static int cCount=0, bCount=0;
void recursion(int secret, int guess) {
	if(secret == 0 || guess == 0) return;

	if( secret % 10  == guess % 10 ) bCount++;
	else cCount++;

	recursion(secret/10, guess/10);
}

int main() {
	int secret = 1807, guess = 7810;

	recursion(secret, guess);
	cout << bCount << "bull " << cCount << "cow" << endl;
}
