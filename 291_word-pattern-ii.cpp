// Pattern Matching: You are given two strings, pattern and value. The pattern string consists of just the letters a and b, describing a pattern within a string. For example, the string catcatgocatgo matches the pattern aabab (where cat is a and go is b). It also matches patterns like a, ab, and b

// source book

#include<iostream>
#include<map>
#include<string>

using namespace std;

map<char, int> mymap;
map<string, int> mymap_string;
int psize, vsize;


void FindDiffrentChar(char c[] , int size) {
	for(int i =0; i <size; ++i ) {
		mymap[c[i]] += 1;
	}
}


string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

bool checker(string s, int a , int b, char patren[]) {
int i = 0, j = 0;
	for(; i < s.size() && j < psize; j++) {
		if(patren[j] == 'a')  { mymap_string[s.substr(i, a)] += 1; i += a; }
		else { mymap_string[s.substr(i,b)] += 1; i += b; }
	}
	cout << i  << " " << s.size() << " " << j << " " << psize << endl;
	if(i== s.size() && j == psize-1) return true;
	else false;
}
		

void PatrenMatch(char value[], char patren[]) {
	FindDiffrentChar(patren, psize);

	int patrencount = mymap.size();
	int pcharsize[patrencount], l=0, i, j;
	for(auto &x: mymap) { pcharsize[l] = x.second; ++l;}
	if(patren[0] == patren[1]) {
		for(i = 1; i < psize; ++i) {
		int x = vsize - (pcharsize[0]*i);
		if((0 == x %pcharsize[1]) && (psize == i+ x/pcharsize[1])) break;
		
		}
	}
	cout << "a = " << i << " b = " << (psize - i) << endl;
	
	string s = convertToString(value, vsize);

	if(checker(s,i, (psize-1), patren)) cout << "True " << endl;
	else cout << "False" << endl;

//	mymap.clear();	
	
}


int main() {
	char value[] = "catcatgocatgo";
	char patren[] ="aabab";
        vsize = (sizeof(value)/sizeof(value[0])) - 1;
        psize = (sizeof(patren)/sizeof(patren[0])) - 1;
	PatrenMatch(value, patren);
	char value1[] = "catgogocatcat";
	char patren1[] = "abbaa";
        PatrenMatch(value1, patren1);

}
