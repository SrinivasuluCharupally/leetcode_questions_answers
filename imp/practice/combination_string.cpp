#include<iostream>
#include<vector>
#include<string>

using namespace std;

void swap(const void *a, const void *b) {
	char tmp = *(char*)b;
	*(char*)b = *(char*)a;
	*(char*)a = tmp;
}


void recursion( string input, int start, int end, string &str, vector<string> &result){
	if(start == end) {
		result.push_back(input);
		return;
	}


	for(int i = start; i <= end; ++i) {
		swap(input[start], input[i]);
		recursion(input, start+1, end, str, result);
		swap(input[start], input[i]);
	}


}

int main() {
	string input = "ABC";
	string str = "";
	vector<string> result;

	int start = 0, end = input.size()-1;

	recursion(input, start, end, str, result);
	for(int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}
}
