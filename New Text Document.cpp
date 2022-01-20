#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool isEnd;
    TrieNode* next[26];
    TrieNode() {
    	isEnd = false;
    	for(int i=0; i<26; i++) next[i] = NULL;
    }
};

struct Trie {
	TrieNode* root;
	void init() {
		root = new TrieNode();
	}

	void insert(string word) {
		TrieNode* cur = root;
		for(int i=0; word[i]; i++) {
			int idx = word[i] - 'a';
			if(cur->next[idx] == NULL) cur->next[idx] = new TrieNode();
			cur = cur->next[idx];
		}
		cur->isEnd = true;
	}

	void printAll(TrieNode *cur, string str) {
		if (cur->isEnd) {
			cout<<str<<endl;
		}
		for(int i=0; i<26; i++) {
			if(cur->next[i]) {
				str += (i+'a');
				printAll(cur->next[i], str);
			}
		}
	}

	void del(TrieNode* cur) {
		for(int i=0; i<26; i++) {
			if(cur->next[i]) {
				del(cur->next[i]);
			}
		}
		delete(cur);
	}
};

Trie wordTrie;

int main() {
	wordTrie.init();
	wordTrie.insert("apple");
	wordTrie.insert("app");
	wordTrie.printAll(wordTrie.root, "");

	return 0;
}
