#include<iostream>
#include<vector>

using namespace std;

bool recursion( int &n , int div) {
	if(div >= n) return true;
	if( n % div== 0) return false;

	div += 1;
	return recursion(n, div);
}

void recursion_bool(bool *divisible , int factor, int &offset, int n) {
	if(offset > n) return;

	offset = offset + factor;
	divisible[offset] = true;

	recursion_bool(divisible, factor, offset, n);
}


void recursion_primelist(vector<int> &primelist, int n, int &index) {
	if(index >= primelist.size()) { 
		primelist.push_back(n) ;
		return;
	}

	if(n % primelist[index] == 0) return;

	index += 1;
	recursion_primelist(primelist, n, index);
}


int main() {
	int n = 15;

// regular brute force
	for(int i = n; i > 1; --i){ 
		int div = 2;
		if(recursion(i, div)) cout << i << " ";
	}
	cout << endl;

// using visited position , elements, eliminate them
	bool divisible[n];
	for(int i = 2; i < n/2+1;  ++i ) {
		int factor1 = i, offset =i;
		recursion_bool(divisible, factor1, offset, n);
	}
	
	for(int i = 2; i <= n; ++i) if(!divisible[i]) cout << i << " ";
	cout << endl;

// using optimzed method, div only with prime numbers
vector<int> primelist;
primelist.push_back(2);
	for(int i = 3; i <= n; ++i){ 
		//int div = 2; 
		int index = 0;
		recursion_primelist(primelist, i, index);
	}
	
	for(int i = 0; i < primelist.size(); ++i) cout << primelist[i] << " ";
	cout << endl;
}
