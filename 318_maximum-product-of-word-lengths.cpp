// simple
//

void recursion(vector<string> words, int index, int movingIndex, int &maxProduct) {
	if(index >= words.size() || movingIndex >= words.size()) return;

	string s1 = words[index];
	string s2 = words[movingIndex];

	//s1.sort();
	//s2.sort();

	for(int s1Index=0, s2Index = 0; s1Index<= s1.size() && s2Index <= s2.size(); s1Index++, s2Index++) {
		if(s1[s1Index] == s2[s2Index]) break;
	}

	if(s1Index<= s1.size() && s2Index <= s2.size()) maxProduct = max(maxProduct, s1.size() * s2.size())

	recursion(words, index, movingIndex++, &maxProduct);

	recursion(words, index++, index+2, maxProduct)
}

int main() {
	vector<string> words = {“abcw”, “baz”, “foo”, “bar”, “xtfn”, “abcdef”};
	
	for(int i = 0; i < words.size(); i++) {
		words[i].sort();
	}
	int maxProduct=1;
	recursion(words, 0, 1, 
}
