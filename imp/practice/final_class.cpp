#include<iostream>

using namespace std;

class myclass {
	int a, b;
  public:
	myclass(): a(10), b(20) {}

	friend class myfriend;

};

class myfriend {
	myclass obj;
	myfriend() {
		obj.a = 30;
	}
};

class notfiend  final  {
	myclass obj1;
	notfiend() {
		// obj1.a = 40; //
	}
};

int main() {


}
