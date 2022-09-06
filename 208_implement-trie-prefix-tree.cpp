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
	vector<string> input = {"zebra", "dog", "duck", "dove"};
	//vector<string> output;

	Trie* output = prefix(input);


}


