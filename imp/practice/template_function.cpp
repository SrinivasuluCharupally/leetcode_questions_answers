#include<iostream>

using namespace std;

template<typename T> 
void function(T i) {
	cout << i << endl;
}


int main() {
	function<int>(1);
	function<float>(2.3);
}
