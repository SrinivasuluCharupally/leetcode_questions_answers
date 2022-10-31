#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
typedef struct activity{
    int start , finish,pos;
} activity;

bool comp(activity s1 , activity s2){
    return (s1.finish < s2.finish);
}
int main()
{
	int t;
    //scanf("%d",&t);
    //while(t--){
        int n=4;
      //  cin >> n;
        activity arr[n];

	cout << "Enter Meeting Rooms time, 4 slots" << endl;

        for(int i =0;i<n;i++) cin >> arr[i].start;
        for(int i =0;i<n;i++) cin >> arr[i].finish;

	for(int i =0;i<n;i++) arr[i].pos=i+1;

        sort(arr,arr+n,comp);
        
	int j=0;
        cout << arr[0].pos;
        
	for(int i=1;i<n;i++){
            if(arr[i].start >= arr[j].finish){
                j=i;
                cout << " " << arr[i].pos;
            }
        }
        cout << endl;
   
	return 0;
}

