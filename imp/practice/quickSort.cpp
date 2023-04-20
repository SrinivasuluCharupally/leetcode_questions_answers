#include<iostream>

#include<vector>

using namespace std;

void swap(int *a , int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}


int pevotPosition(vector<int> &input, int start, int end) {
	
	int pevot = input[end-1];
	int right = end-2;
	int left = start;
	while(left < right) {
		while(input[left] < pevot && left < right) 
			left++;
		while(input[right] > pevot && right > left) 
			right--;
		swap(input[left] , input[right]);
		left++; right--;
	}

	swap(input[left] , input[end-1]);
	return left;
}

void quickSort(vector<int> &input, int start, int end) {
	if(start < end) {
		int p = pevotPosition(input, start, end);
		quickSort(input, start, p-1);
		quickSort(input, p+1, end);
	}
}



int main() {
	vector<int> input = { 5,7,0,2,4,6,1};
	
	int start = 0, end = input.size();
	quickSort(input, start, end);

	for(int i =0; i < input.size(); ++i) cout << input[i] << " " ;
	cout << endl;
	
}



