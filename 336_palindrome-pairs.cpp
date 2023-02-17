#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;


bool isPalindrome(const string s){

int i =0; int j = s.size()-1;

    while (i<j)
    {
        if (s[i] == s[j])
        {
            ++i; --j;
        }
        else
            return false;
    }
    return true;
}

void recursion(vector<string> str, int &first, int second, string tempArray, vector<string> &resultMatrix) {
	if( second >= str.size() || first >= str.size() )  {
		return;
	}

	string tmp  = str[first] + str[second];
//	cout << tmp << endl;
	if(isPalindrome(tmp)) { 
		cout << "[ " << first << " , "  << second << " ]  ==> "  ; 
		cout << "[ " << str[first] << " , "  << str[second] << " ] " << endl ; }
	recursion(str, first, second+1, tempArray, resultMatrix);
	first += 1;
	recursion(str, first, 0,  tempArray, resultMatrix);
}

int main() {
	vector<string> str = { "abcd","dcba","lls","s","sssll" };

	string  tempArray = "";
	
	vector<string> resultMatrix;
	int first=0, second=1; 

	recursion(str, first, second, tempArray, resultMatrix);

//	for(int i =0; i < resultMatrix.size(); i++) {
//		cout << resultMatrix[i] << secondl;
//	}
//	return 0;
}




