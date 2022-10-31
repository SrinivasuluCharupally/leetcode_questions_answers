// all combinations of string, having dublicate characters in string, recusive technique
//source http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

#include<iostream>
#include<string>
#include<stdio.h>
#include<set>

using namespace std;

bool findpermutation(string s) {

 for(int i=0;i < s.length() ;i++){
        if(s[i] != s[s.length()-i-1]){
            //flag = 1;
            //break;
	    return false;
           }
        }
  return true;

}

void swap(char* x, char* y) {
	char tmp = *x;
	*x = *y;
	*y = tmp;
}

void AllPermutationsOfString(set<string>* setOfCombinations, char* c, int left, int right) {
	
	if(left == right) { /*printf("%s\n", c); */ setOfCombinations->insert(c); }
	else {
		for( int i =left; i <= right; i++) {
			swap((c+left), (c+i));
			AllPermutationsOfString(setOfCombinations, c, left+1, right);
			swap((c+left), (c+i));
		}
	}
}


int main() {
	char s[] = "aabcb";
	int length = sizeof(s)/sizeof(s[0]);
	cout << length << endl;
	set<string>* setOfCombinations = new set<string>;
	AllPermutationsOfString(setOfCombinations, s, 0, length-2);



	cout << "Avoid dublicate permutations" << endl ;
	for(set<string>::iterator itr = setOfCombinations->begin(); itr != setOfCombinations->end(); ++itr)
		if(findpermutation(*itr) ) cout << *itr << endl;


	return 0;
}


