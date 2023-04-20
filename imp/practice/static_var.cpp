#include<iostream>

using namespace std;

void fun() {
	static int i = 0;
	cout << i << endl;
	i++;
}


int main() {
	fun();
	fun();
	//extern int i;
	//i++;
	void (*fp)();
	fp = fun;
	fp();

	int a[] = {1,2,3};
	int *p = new int[3](); // this initialize all 3 elements with zero
	int *p1 = new int[3] {5,6,7}; // this init all 3 elements with given list
	cout << a[1] << endl;
	cout << *p << endl;
	cout << *p1 << endl;
}
