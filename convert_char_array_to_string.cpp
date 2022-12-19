// Pattern Matching: You are given two strings, pattern and value. The pattern string consists of just the letters a and b, describing a pattern within a string. For example, the string catcatgocatgo matches the pattern aabab (where cat is a and go is b). It also matches patterns like a, ab, and b

// source book

#include<iostream>
#include<map>
#include<string>

using namespace std;



string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

		


int main() {
	int vsize, psize;
	char value[] = "catcatgocatgo";
	char patren[] ="aabab";
        vsize = (sizeof(value)/sizeof(value[0])) - 1;
        psize = (sizeof(patren)/sizeof(patren[0])) - 1;
	char value1[] = "catgogocatcat";
	char patren1[] = "abbaa";

	string s = convertToString(value, vsize);
	cout << s << endl;
}
