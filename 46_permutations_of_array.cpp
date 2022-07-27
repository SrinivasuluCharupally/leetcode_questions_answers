#include<iostream>
#include<vector>

using namespace std;


void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//permutation function
void permutation(int *arr, int start, int end)
{
    if(start==end)
    {
	    for(int i=0; i<=end; i++){  printf("%d\t",arr[i]);  }
	    cout << endl;
//        printarray(arr, end+1);
        return;
    }
    int i;
    for(i=start;i<=end;i++)
    {
        //swapping numbers
        swap((arr+i), (arr+start));
        //fixing one first digit
        //and calling permutation on
        //the rest of the digits
        permutation(arr, start+1, end);
        swap((arr+i), (arr+start));
    }
}

int main() {
	int arr[3] = {1,2,3};
	int size = sizeof(arr) / sizeof(arr[0]);
	permutation(arr, 0, size-1);

}
