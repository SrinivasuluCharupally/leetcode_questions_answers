#include<iostream>
#include<string>

using namespace std;


void recursion(string a, string b, int &asize, int &bsize, string &output, bool &carry) {
	if(asize < 0 || bsize < 0 ) { 
		if(carry == true) output.insert(0,"1");

		cout << output << endl ; return; 
	}
	

	if(a[asize] == 49 && b[bsize] == 49) {
		if(carry == true ) { output.insert(0,"1"); carry = true; }
		else { output.insert(0,"0"); carry = true; }
	}
	else if(a[asize] == 49 || b[bsize] == 49) {
		if(carry == true ) { output.insert(0,"0"); carry = true; }
                else { output.insert(0,"1"); carry = false; }
	}
	else {  if(carry == true ) { output.insert(0,"1"); carry = false; }
                else { output.insert(0,"0"); carry = false; }
        }

	asize -= 1; bsize -= 1;


	recursion(a,b, asize, bsize, output, carry);

		
}

int main() {
	string a = "1010";
	string b = "1011";
	int asize = a.size()-1, bsize=b.size()-1;
	bool carry = 0;
	
	string output;

	recursion(a, b, asize, bsize, output, carry);
}
