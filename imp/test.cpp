#include<iostream>
#include<exception>

using namespace std;

static int z = 0;

class X {
	public:
		X() {
			std::cout << 'X';
			if(z++ == 0) {
				throw std::exception();
			}
		}
		~X() {
			std::cout << "~X";
		}

};

class Y {
	public:
		Y() { std::cout << 'Y' ; }
		~Y() { std::cout << "~Y"; }

		X x;
};

void f() {
	static Y y;
}

int main() {

	float a = 3.45, b = 3.56;
	cout <<  (a<b ? a :b ) << endl;
	try {
		f();
	}


	catch (std::exception &) {
		std::cout << 'Z';
		f();

	}
}
