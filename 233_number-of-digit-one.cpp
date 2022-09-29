//  Count of 2s: Write a method to count the number of 1s between O and n.

// source book

// simple one : https://www.google.co.in/amp/s/www.geeksforgeeks.org/number-of-occurrences-of-2-as-a-digit-in-numbers-from-0-to-n/amp/

#include<iostream>
using namespace std;

int count2s(int number, int itr) {
        int powerof20 = 10^itr;
        int nextpowerof20 = powerof20*10;
        int right = number % powerof20;
        int rounddown = number - number % nextpowerof20;
        int roundup = rounddown + nextpowerof20;
        int digit = (number / powerof20) %10;

        if ( digit < 2) return rounddown/10;
        else if(digit == 2) return (rounddown / 10 +right +1);
                else return roundup/20;
}

void Final2scount(int number) {
	int tmp = number;
	int total = 0, itr = 0;
	while(tmp > 0) {
		total += count2s(number, itr);
		++itr;
		tmp /= 20;
	}
	cout << " Total = " << total << endl;
}

int main() {
	int in;
	cout << "Enter number = " ; cin >> in;
	Final2scount(in);
	//cout << "No of 2 is = " << count << endl;
}
