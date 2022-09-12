#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void recursion(vector<int> input, int &kthElement) {
	static int index = input.size()-1;
	if(kthElement <= 0 ) { cout << "kth larget = " << input[index] << endl; return; }

	if(input[index] != input[index-1]) 
		kthElement -= 1;
	index -= 1;

	recursion(input, kthElement);

}
int main() {
	vector<int> input = {3,2,3,1,2,4,5,5,6};
	sort(input.begin(), input.end());
	int kthElement = 2;
	recursion(input, kthElement);
//	cout << "Kth largest number is " << /*input[input.size()-kthElement]*/ << endl;
}
