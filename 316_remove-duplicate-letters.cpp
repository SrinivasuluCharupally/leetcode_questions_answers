
void recursion(string input, int index, bool &tracker) {
	if(index > input.size()) return;

	if( !tracker[input[index]]) { cout << input[index] ; tracker[input[index]] = true ; }
	
	recursion(input, index++, tracker);
}


int main() {
	string input = "cbacdcbc";
	bool tracker[26] = {false};

	recursion(input, 0, tracker) ;
}
