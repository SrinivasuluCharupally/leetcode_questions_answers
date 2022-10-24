#include<vector>
#include<iostream>

//#include <bits/stdc++.h>
using namespace std;


    static int currIndex=0;

    static int n;
 
void recursion(vector<vector<int> > &v, vector<vector<int>::iterator> &iStart, vector<vector<int>::iterator> &iEnd )
    {
 	static int index = 0;
	if(index >= v.size()) return;
 
            iStart[index] = v[index].begin();
            iEnd[index] = v[index].end();

       index++;
       recursion(v, iStart, iStart);
    }
 
int main()
{
    vector<vector<int> >
        v{ { 1, 2 },
        { 3 },
        { 4, 5, 6 },
        { 7, 8, 9, 10 } };
    
    vector<vector<int>::iterator> iStart;
    vector<vector<int>::iterator> iEnd; 

	n = v.size();
        iStart.resize(n);
        iEnd.resize(n);
    
        recursion(v, iStart, iEnd);

	int i = 0;
	for(vector<int>::iterator itr = v[3].begin(); itr != v[3].end(); itr++) {
		cout << *itr << endl;
	}

// For some reason, this code is not working
    while (i < n) {
	    vector<int>::iterator itr =  iStart[i] ;
	    while(itr != iEnd[i]) { 
	       cout << *itr << " ";
	       itr++;
	    }
	    i++;
	//}
 
    return 0;
}
