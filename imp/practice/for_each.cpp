#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print(int a) {
	cout << a << endl;
}

int main() {
	vector<int> input = {1,2,3,4};

	for_each(input.begin(), input.end(), print);

	for(auto x : input) {
		cout << x << endl;
	}
}
