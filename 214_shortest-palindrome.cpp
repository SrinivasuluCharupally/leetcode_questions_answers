#include<iostream>
#include<vector>

using namespace std;

void recursion(string input, int &left, int &right, int &addingCharCount) {
	if(left>=right) return;

	if(input[left] == input[right]) {
		left += 1;
		right -= 1;

	}
	else {
		addingCharCount += 1;
		right -= 1;
	}


	recursion(input, left, right, addingCharCount);


}

int main() {
	string input = "aacecaaa";
	int left=0, right=input.size()-1;

	int addingCharCount=0;

	recursion(input, left, right, addingCharCount);
	cout << "No of char adding in the front of string are " << addingCharCount << endl;

}
