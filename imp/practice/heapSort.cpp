#include<iostream>
#include<vector>

using namespace std;

void swap( int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapify(vector<int> &input, int n, int i) {
	int least = i;
	int left = 2*i + 1;
	int right = 2*i + 2;

	if( left < n && input[least] < input[left]) least = left;
	if(right < n && input[least] < input[right]) least = right;

	if(least != i) {
		swap(input[i], input[least]);
		heapify(input, n, least);
	}
}

void heapSort(vector<int> &input) {

	int n = 5; // 5; // 5; // 5; // 5; // sizeof(input) / sizeof(input[0]);
	for(int i = n/2 -1; i >=0; --i) {
		heapify(input, n, i);
	}


	for(int i = n-1; i >= 0; --i) {
		swap(input[0], input[i]);
		heapify(input, i, 0);
	}

}

int main() {
	//int input[] = {8,5,1,0,9};
	vector<int> input = {8,5,1,0,9};

	heapSort(input);

	for(int i = 0; i < 5; i++) {
		cout << input[i] << " " ;
	}
	
}
