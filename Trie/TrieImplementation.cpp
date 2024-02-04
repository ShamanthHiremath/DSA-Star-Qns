// #include<bits/stdc++.h>
#include <string.h>
#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    // A-Z children for each node
    TrieNode *children[26];
    // To check if the node is an end point of a word
    bool isTerminal;
    TrieNode(char d)
    {
        data = d;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    // Initialize root with an empty character
    Trie()
    {
        root = new TrieNode('\0');
    }

    // Insert helper fn
    void insertUtil(TrieNode *root, string word)
    {
        // size of word is 0
        if (!word.length())
        {
            root->isTerminal = true;
            return;
        }
        // A-Z indexing
        int index = word[0] - 'A';
        // to store that position node in child
        TrieNode *child;

        // node is present
        if (root->children[index])
        {
            child = root->children[index];
        }
        // absent
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // RecursiveCall
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        if (!word.length())
        {
            return root->isTerminal;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        // if that char is present
        if (root->children[index])
        {
            child = root->children[index];
        }
        // absent
        else
        {
            return false;
        }

        // Recursive call
        return searchUtil(child, word.substr(1));
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }

    void deleteUtil(TrieNode *root, string word)
    {
        if (!word.length())
        {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'A';

        TrieNode *child = root->children[index];

        // If the character is present
        if (child) {
            deleteUtil(child, word.substr(1)); // Recur for the next character
        // If child node is not the end of any word and has no other children, delete it
            if (!child->isTerminal && allChildrenNull(child)) {
                delete child;
                root->children[index] = nullptr; // Set the pointer to null after deletion
            }
        }
    }

    void deleteWord(string word)
    {
        if (!search(word))
        {
            cout << "Word doesn't exist";
            return;
        }
        else
        {
            deleteUtil(root, word);
        }
    }

    // Helper function to check if all children of a node are nullptr
    bool allChildrenNull(TrieNode *node)
    {
        for (int i = 0; i < 26; ++i)
        {
            if (node->children[i] != nullptr)
            {
                return false; // At least one child is not nullptr
            }
        }
        return true; // All children are nullptr
    }


};

int main()
{
    Trie t;
    t.insertWord("XYZ");
    t.insertWord("OH");
    cout << t.search("XYZ");
    t.deleteWord("XYZ");
    cout << t.search("XYZ");
    t.deleteWord("ANS");

    return 0;
}