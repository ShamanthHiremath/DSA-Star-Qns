/*
126. Word Ladder II

https://leetcode.com/problems/word-ladder-ii/description/

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].


Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
*/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
        // a set DS to store the wordList for quick lookup (O(1) with unordered_set)
        unordered_set<string> st(wordList.begin(), wordList.end());
        // if endWord is not in the dictionary, there is no valid transformation
        if(!st.count(endWord)) return {};

        vector<vector<string>> ans;

        // queue stores the current path (not just the word)
        queue<vector<string>> q;
        // inserting the first word with its path
        q.push({beginWord});

        // visited set to store the words already visited in previous levels
        unordered_set<string> visited;
        bool found = false; // flag to break after finding shortest sequences

        while(!q.empty() && !found){
            int sz = q.size();
            unordered_set<string> visitedThisLevel;

            for(int i = 0; i < sz; i++){
                vector<string> path = q.front();
                q.pop();

                string word = path.back(); // get last word in current path

                // try changing every character of the word
                for(int j = 0; j < word.size(); j++){
                    string temp = word;

                    // try replacing with every possible lowercase character
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        temp[j] = ch;

                        // if the new word exists in the dictionary and not visited before
                        if(st.count(temp) && !visited.count(temp)){
                            vector<string> newPath = path;
                            newPath.push_back(temp);

                            if(temp == endWord){
                                // found one of the shortest paths
                                ans.push_back(newPath);
                                found = true; // we can finish current level but not go further
                            }
                            else {
                                q.push(newPath);
                            }

                            visitedThisLevel.insert(temp); // mark visited at this level
                        }
                    }
                }
            }

            // after finishing the level, mark words as visited globally
            for(string w : visitedThisLevel){
                visited.insert(w);
            }
        }

        return ans;
    }
};
