#include<iostream>
#include<vector>
#include<string>

using namespace std;

void recursion(string input, int &index, int &maxlength, bool tracker[26], int &counting) {
	if(index >= input.size()) return;
	
	if(tracker[input[index] - 96] == false) {
		tracker[input[index] - 96] = true;
		counting++;
	}
	else {
		if(maxlength < counting) { maxlength = counting; counting = 1; }
		for(int i = 0; i < 26 && tracker[index] != false; i++) { tracker[i] = false;} 
		tracker[input[index] - 96] = true;
	}
	index +=1;
        recursion(input, index, maxlength, tracker, counting);	

}

int main() {
	string input = "pwwkew";

	int index = 0, maxlength = 0, counting=0;
	bool tracker[26] = {false};
	recursion(input, index, maxlength, tracker, counting);
	//printf(" finding char equal int value %di \n" , input[4]-96 );
	cout << maxlength << endl;
}
