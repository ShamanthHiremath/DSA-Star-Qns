/*
127. Word Ladder

https://leetcode.com/problems/word-ladder/

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.


Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // a set DS to store the wordList
        set<string>st;
        for(string s: wordList){
            st.insert(s);
        }
        // imagine each word is a unique node 
        // the edges/links are the transformations we check at each letter and check if it exists in the set.
        // the point here is to visualise the updates we are making in the word at every letter leads to a new level,
        //  hence we check for all 26 alphabets, and check if there is a new link to a unique word in the set. and increment the transformations made as level in the imaginary graph.
        //  if there is a word that gets formed and matches the endWord, we return the length, or else 0 

        // to store string and the no of transformations
        queue<pair<string, int>>q;
        // inserting the first word
        q.push({beginWord, 1});

        while(!q.empty()){
            // pop the nodes from each level
            auto [word, trnstn] = q.front();
            q.pop();

            // try each possible chnage for each letter in the word, and add edges/links (not done tho) to next level
            for(int i=0; i<word.size(); i++){
                char oldCh = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    // change the letter to a new possible letter
                    word[i] = ch;

                    // checks if the new transformed word exists in the set or not
                    if(st.count(word)){
                        if(word == endWord){
                            // return the level / no of transformations made
                            return trnstn+1;
                        }
                        q.push({word, trnstn+1});

                        // remove the word from set, since it is already formed
                        st.erase(word);
                    }
                }
                // backtrack to same old
                word[i] = oldCh;
            }
        }

        return 0;
    }
};