#include<iostream>
#include<string>
#include<vector>

using namespace std;


int main() {
	string input1 = "12", input2 = "10", result = "";

	int in1 = stoi(input1);
	int in2 = stoi(input2);
	int res = in1 * in2;
	cout << res << endl;

	result = to_string(res);

	cout << result << endl;
}
