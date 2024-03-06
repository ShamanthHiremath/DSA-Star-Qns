/*
Sample Input 1 :

5
cod coding codding code coly
coding

Sample Output:
The suggestions for “c” is {“cod”, “coding”, “codding”, “code”, “coly”}.
cod coding codding code coly

The suggestions for “co” is {“cod”, “coding”, “codding”, “code”, “coly”}.
cod coding codding code coly

The suggestions for “cod” is {“cod”, “coding”, “codding”, “code”, “coly”}.
cod coding codding code coly

The suggestion for “codi” is {“coding”}.
coding

The suggestion for “codin” is {“coding”}.
coding

The suggestion for “coding” is {“coding”}.
coding
*/
#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char d) {
        data = d;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode *root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word) {
        if (word.empty()) {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index]) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word) {
        if (word.empty()) {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index]) {
            child = root->children[index];
        } else {
            return false;
        }
        return searchUtil(child, word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root, word);
    }

    void printSuggestions(TrieNode* curr, vector<string>& temp, string prefix) {
        if (curr->isTerminal) {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode* nextletter = curr->children[ch - 'a'];
            if (nextletter != nullptr) {
                prefix.push_back(ch);
                printSuggestions(nextletter, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str) {
        TrieNode* prev = root;
        vector<vector<string>> ans;
        string prefix = "";

        for (char lastch : str) {
            prefix.push_back(lastch);
            TrieNode* curr = prev->children[lastch - 'a'];
            if (curr == nullptr) {
                break;
            }
            vector<string> temp;
            printSuggestions(curr, temp, prefix);
            ans.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return ans;
    }
};

vector<vector<string>> phoneDirectory(vector<string>& contactList, string &queryStr) {
    Trie *t = new Trie();
    for (auto& i : contactList) {
        t->insertWord(i);
    }
    return t->getSuggestions(queryStr);
}