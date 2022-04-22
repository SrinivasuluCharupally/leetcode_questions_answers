#include<iostream>
#include<string>

using namespace std;

bool recursion(string input, int &index, bool &sign, bool &decimal, bool &expo) {
	if(index > input.size()-1) return true;

	if((input.compare(index,1,"-") == 0 || input.compare(index,1,"+") ==0) && sign == false && expo == false) 
		sign = true;
	else if(input[index] <=58 && input[index] >=48) 
		cout << input[index]; 
	else if((input.compare(index,1,".") == 0) && decimal==false) 
		decimal=true;
	else if(((input.compare(index,1,"e")==0) || (input.compare(index,1,"E")==0) ) && (input[index+1] <=58 && input[index+1] >=48)  ) 
		expo=true;
	else 
		return false;
	
	index += 1;
	return recursion(input, index, sign, decimal, expo);
	
}


int main() {
	string input = "2e10";

	int index = 0;
	bool sign=false, decimal=false, expo=false;

	cout << recursion(input, index, sign, decimal, expo) << endl;
}
