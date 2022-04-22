#include<iostream>
#include<string>

using namespace std;

void recusion(string input, int &index, int &count) {
	if(index < 0 || ((input.compare(index, 1," ") ==0)  && count !=0) ) { cout << "count = " << count << endl ; return; }

	if(input.compare(index,1 ," ")==0) { 
		index -= 1; 

	}
	else { 
		count += 1;
		index -= 1;
	}

        recusion(input, index, count);

}

int main() {
	string input = "   fly me   to   the moon  ";
	int index = input.size()-1;
	int count = 0;
	recusion(input, index, count);
}

