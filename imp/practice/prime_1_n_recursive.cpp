#include<iostream>
#include<vector>

using namespace std;

void recursion( int &n, vector<int> &primeList, int &current, int &index) {
	if( current > n) return;
	if(index >= primeList.size() ) { primeList.push_back(current); return; }

	else if( current % primeList[index] == 0) return;
	
	index += 1;
	recursion(n, primeList, current, index);

	index = 0; current +=2;
	recursion(n, primeList, current, index);

}

int main() {
	vector<int> primeList = {2};

	int n = 30, current = 3, index = 0;

	recursion(n, primeList, current, index);

	for(int i = 0; i < primeList.size(); ++i) 
		cout << primeList[i] << endl;
}

