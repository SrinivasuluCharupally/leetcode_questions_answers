#include<iostream>
#include<vector>
#include<set>

using namespace std;

void recursion(vector<int> input, set<int> &myset, int windowSize) {

	static int index = 0;
	if(index >= input.size() - 2) return;

	for(int i = index; i <= (index + windowSize); i++)
		myset.insert(input[i]);

	set<int>::iterator itr = myset.end(); /// set<> container does sorting by default, so
					      /// simply pick the first element which is max
	itr--;
	cout << *itr << endl;
	myset.clear();
	index += 1;
	recursion(input, myset, windowSize);

}

int main() {
	vector<int> input = {1, 3, -1, -3, 5, 3, 6, 7};
	set<int> myset;
	int windowSize = 3;

	recursion(input, myset, windowSize-1);
}
