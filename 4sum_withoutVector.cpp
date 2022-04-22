#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int sum(vector<int> output) {
	int sum = 0;
	for(int i = 0; i < 4; i ++) sum += output[i];

	return sum;
}

void print(vector<int> output) {
		for(int i = 0; i < output.size(); i++) {
			cout << output[i] << " ";
		}
		cout << endl;
}



void recursion(vector<int> input, int &offset1, int &offset2, int &left, int &right, int target) {
        if(left >= right || offset1 >= input.size()-4 || offset2 >= input.size()-3  ) return;

        int sum = input[offset1] + input[offset2] + input[left] + input[right];

        if(sum == target) {
                cout << input[offset1] << " " << input[offset2] << " " << input[left] << " " << input[right] << endl;
		left +=1; right -=1;
                recursion(input, offset1, offset2, left, right, target);  }
        else if(sum > 0) { right -=1; recursion(input, offset1, offset2, left, right, target ); }
        else if( sum <0) { left += 1; recursion(input, offset1, offset2, left, right, target ); }

        offset2 +=1;
        left = offset2+1;
	right = input.size()-1;
        recursion(input, offset1, offset2, left, right, target);


        offset1 +=1; 
	offset2 = offset1+1;
        left = offset2+1;
	right = input.size()-1;
        recursion(input, offset1, offset2, left, right, target);



}

	

int main() {
	vector<int> input = {1,0,-1,0,-2,2}; // -2, -1, 0, 0, 1, 2

	sort(input.begin(), input.end());

	vector<int> output;
	int index = 0, offset1 = 0, offset2 = 1, left = 2; 
	int target = 0;
	int right = input.size()-1;
	recursion(input, offset1, offset2, left, right, target);

}
