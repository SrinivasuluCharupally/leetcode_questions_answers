#include<iostream>
#include<vector>

using namespace std;

struct Trie
{
    Trie *edges[26];
    int words;
    Trie()
    {
        for (auto i = 0; i<26; ++i)
            edges[i] = NULL;
        words = 0;
    }
};

void addToTrie(Trie* head, string s)
{
    int n = s.length();
    Trie *current = head;

    for (auto i = 0; i<n; ++i)
    {
        current->words += 1;
        if (!current->edges[s[i]-'a'])
            current->edges[s[i]-'a'] = new Trie();
        current = current->edges[s[i]-'a'];
    }
}

bool search(Trie* head, string word) {
	// implement the simple search to find the given string.
}

Trie* prefix(vector<string> &A) {
    if (A.empty())
        return NULL;
    Trie *head = new Trie();

    auto size = A.size();
    for (auto i = 0; i<size; ++i)
        addToTrie(head, A[i]);


    return head;
}

int main() {
	vector<string> input = {"bad","dad","mad"};
	//vector<string> WordDictionary;

	Trie* WordDictionary = prefix(input);


}


