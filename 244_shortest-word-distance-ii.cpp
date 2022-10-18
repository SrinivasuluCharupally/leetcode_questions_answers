#include<iostream>
#include<string>
#include<climits>
#include<cstring>
#include<vector>

using namespace std;


int shortestDistance( vector<string> words, string word1, string word2) {
        int i1 = -1;
        int i2 = -1;
        int shortest = INT_MAX;

        for (int i = 0; i < words.size(); i++) {
            if (words[i].compare( word1)) {
                i1 = i;
            }
            if (words[i].compare(word2)) {
                i2 = i;
            }

            if (i1 != -1 && i2 != -1) {
                shortest = min(abs(i1 - i2), shortest);
            }
        }
        return shortest;
}



int main() {
	vector<string> input ={"practice", "makes", "perfect", "coding", "makes"};
	string word1 = "coding", word2 = "practice";

	shortestDistance(input, word1, word2);

}
