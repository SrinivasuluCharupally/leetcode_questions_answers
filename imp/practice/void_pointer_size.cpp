#include<iostream>

using namespace std;


int main() {
	void *p = (void *) malloc(101);
	
	int i[3] ;
	cout << size_t(p) << endl;
	cout << size_t(i) << endl; // 

	cout << sizeof(i) << endl; // it gives 12 bytes, 3 int elements
}

