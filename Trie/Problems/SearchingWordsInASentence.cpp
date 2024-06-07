/*
In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.
*/

class Trie {
public:
    Trie* next[26];
    bool terminal;

    Trie() {
        terminal = false;
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    }

    void insert(Trie* root, const string& word) {
        Trie* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (!curr->next[index]) {
                curr->next[index] = new Trie();
            }
            curr = curr->next[index];
        }
        curr->terminal = true;
    }

    string search(Trie* root, const string& word) {
        Trie* curr = root;
        int rootLength = 0;
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            int index = c - 'a';
            if (!curr->next[index]) {
                break; // No root found
            }
            curr = curr->next[index];
            if (curr->terminal) {
                rootLength = i + 1; // Update shortest root length if found
                break; // Optional: stop early if a root is found
            }
        }
        return rootLength > 0 ? word.substr(0, rootLength) : word; // Return the shortest root substring or the original word
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* root = new Trie();
        for (const string& word : dictionary) {
            root->insert(root, word);
        }

        istringstream iss(sentence);
        string word;
        string ans;

        while (iss >> word) {
            string replacement = root->search(root, word);
            if (!ans.empty()) {
                ans += " ";
            }
            ans += replacement;
        }

        return ans;
    }
};