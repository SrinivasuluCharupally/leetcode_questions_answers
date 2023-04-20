#include<iostream>
using namespace std;


void add(int, int);

typedef void (*add_callback)(int, int);

void add(int a, int b) {
	cout << "addition " << a+b << endl; 
}


void invokCallback(int a, int b, add_callback add_callback_func) {

	a = a+10; b = b+20;
	add_callback_func(a, b);
}

int main() {
	invokCallback(1,2, add);
}
