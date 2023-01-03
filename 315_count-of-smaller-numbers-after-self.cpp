// it's simple
//
//

void recursion(vector<int> input, int index, int rightMover, int &count) {
	if(index >= input.size() || rightMover >= input.size()) {
		cout << countr << " " ; count = 0; return;
	}

	if(intput[rightMover] < input[start] ) count += 1;
	//rightMover += 1;
	recursion(input, index, rightMover+1, count);
	index += 1; rightMover = index+1;
	recursion(input, index, rightMover, count);
}

int main()( {
	vector<int> input = {5,2,6,1};
	int count = 0;
	recursion(input, 0, 1, count);

}	
