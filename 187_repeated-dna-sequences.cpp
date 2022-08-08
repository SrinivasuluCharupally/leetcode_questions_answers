#include<iostream>
#include<string>
#include<vector>

using namespace std;

void recursion(string input, vector<string> &output, int &index) {
	if(index+10 > input.size()) return;

	string tmp = input.substr(index,10);
	std::size_t repeat_found = input.find(tmp, index+10);
        if (repeat_found != std::string::npos)
		cout << "found at Index " << repeat_found << " is " << tmp << endl;
	
	index += 1;
	recursion(input, output, index);

}


int main() {
	string input = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	int index = 0;
	vector<string> output;
	recursion(input, output, index);

}

