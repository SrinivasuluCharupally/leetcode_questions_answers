#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &arr, int left, int mid, int right) {

 
 int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
 
    i = 0;
    j = 0;
    k = left;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }


//	int tmp[end];
//
//	int l1, l2, i;
//	for(l1 = start , l2 = mid , i=start; l1 <= mid && l2 <= end; i++) {
//		if(input[l1] <= input[l2]) tmp[i] = input[l1++];
//		else tmp[i] = input[l2++];
//	}
//
//	while(l1 <= mid) tmp[i++] = input[l1++];
//	while(l2 <= end ) tmp[i++] = input[l2++];
//
//	for(int k =start; k <= end; k++) 
//		input[k] = tmp[k];
}

void mergeSort(vector<int> &input, int start, int end) {
	if(start < end ) {

	int mid = (start+end) / 2;
	mergeSort(input, start, mid);
	mergeSort(input, mid+1, end);

	merge(input, start, mid, end);
	}
}


int main() {
	vector<int> input = { 5, 1,0,8,2,9};

	mergeSort(input , 0, input.size()-1);

	for(int i = 0; i < input.size(); i++) cout << input[i] << " ";
}

