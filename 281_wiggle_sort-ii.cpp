// wave sort : Example: (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].
//
//

#include<iostream>

using namespace std;


void wiggleSort(int nums[]) {

        for (int i = 1; i < 6 /*nums.length*/ ; ++i) {

            if ((i % 2 == 1) != (nums[i] > nums[i - 1])) {

                int cache = nums[i];

                nums[i] = nums[i - 1];

                nums[i - 1] = cache;

            }
	}

	for(int i = 0; i < 6; i++) cout << nums[i] << " " ;
}

int main() {
	int nums[] = {1,3,2,2,3,1};

	wiggleSort(nums);
}
