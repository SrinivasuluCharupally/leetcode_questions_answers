// details : https://xiaoguan.gitbooks.io/leetcode/content/LeetCode/320-generalized-abbreviation-medium.html
//

string createword(int localindex, string word) {
	while(localindex >0) {
		int count=0;
		while (localindex & 1 ) {
			localindex >> 1;
			count+1;
		}
		if( ! localindex & 1 ) localindex>> 1;
		word.replace(pos, count, count);
		
	}
	return word;
}


void recursion(input, index, noOfChars) {
	if(index >= noOfChars) return;

	cout << createword(index, word) << endl;
	recursion(input, index+1, noOfChars);
}

int main() {
	string input = "word";

	int noOfChars =2^(input.size());
	recursion(input, index, noOfChars);
}
