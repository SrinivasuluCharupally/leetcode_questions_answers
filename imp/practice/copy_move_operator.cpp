#include<iostream>

using namespace std;


class test {
	int *ptr=NULL;

public:
	test(int *x = NULL) : ptr(x) {} 

	test(test& a) {
		ptr = new int;
		*ptr = *a.ptr;
	}

	test(test&& a) {
		//delete ptr;
		ptr = a.ptr;
		a.ptr = NULL;
	}

	test* operator =(test& a) {
		if(this == &a) return this;
		
		delete ptr;
		ptr = new int;
		*ptr = *a.ptr;
		return this;
	}

	test* operator=(test&& a) {
		if(this == &a) return this;
		
		delete ptr;
		ptr = a.ptr;
		a.ptr = NULL;
		return this;
	}
};

int main() {
	test a(new int);
	test b;
}

