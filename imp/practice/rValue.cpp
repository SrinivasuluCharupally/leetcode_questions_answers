#include<iostream>


using namespace std;

int main() {
	int a = 10;
	int &b = a;

	int && c = 20; 

	cout << "a =   " << a << endl;
	cout << "&a =  " << &a << endl;
	cout << "b =   " << b << endl;
	cout << "&b =  " << &b << endl;
	cout << "c  =  " << c << endl;
	cout << "&&c = " << &c << endl;
	cout << "&&c = " << &&c << endl;
}
