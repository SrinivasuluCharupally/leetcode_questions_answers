#include<iostream>

using namespace std;

class myexception {
 public:
	string s;

 
	myexception(string a) : s(a) {}

};

int main() {

	int n = -1;

	try {
		if(n < 0) {
			throw myexception("not a number");
		}
	}

	catch(myexception e) {
		cout << e.s << endl;
	}

}
