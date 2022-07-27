#include<iostream>
#include<string>
#include<cstring>

using namespace std;

void recursion(string input, int &output, int &index, int &sign) {
	
	if(input[index] >= 96 || index >= input.size()) { output *= sign; return; }
	const char c = input[index];

	if(input.compare(index, 1, " ") == 0)  { 
		index += 1; recursion(input, output, index, sign); }
	else { if(input.compare(index,1, "-" ) == 0)  { sign *= -1; }
	       else { string k = input.substr(index); output = stoi(k); 
		       index += k.size()-1;
	      		 } 
//			output = (output*10) + atoi((const char*)c);
//		}
		index += 1;
		recursion(input, output, index, sign);
	}
	
}


int main() {
	string input = "  -4193 with words";
	int output=0, index=0, sign = 1;

	recursion(input, output, index, sign);
	cout << output << endl;
}
