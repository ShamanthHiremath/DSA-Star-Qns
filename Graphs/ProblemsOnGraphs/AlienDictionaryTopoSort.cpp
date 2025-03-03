/*
Alien Dictionary

https://www.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=alien-dictionary

A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

Examples:
Input: words[] = ["cb", "cba", "a", "bc"]
Output: true
Explanation: You need to return "cab" as the correct order of letters in the alien dictionary.

Input: words[] = ["ab", "aa", "a"]
Output: ""
Explanation: You need to return "" because "aa" is lexicographically larger than "a", making the order invalid.

Input: words[] = ["ab", "cd", "ef", "ad"]
Output: ""
Explanation: You need to return "" because "a" appears before "e", but then "e" appears before "a", which contradicts the ordering rules.
*/

class Solution {
    private: 
      bool topoSortDFS(int node, unordered_map<int, list<int>>&adj, vector<int>&visited, stack<int>&st){
          if(visited[node] == 1){
              return true;
          }
          if(visited[node] == 2){
              return false;
          }
          
          visited[node] = 1;
          
          for(int nbr: adj[node]){
              if(topoSortDFS(nbr, adj, visited, st)){
                  return true;   
              }
          }
          visited[node] = 2;
          
          st.push(node);
          return false;
      }
    public:
      string findOrder(vector<string> &words) {
          // code here
          if (words.empty()) {
              return "";
          }
          
          unordered_map<int, list<int>>adj;
          
          for(int i=0; i<words.size()-1; i++){
              // testing two cons words only
              string word1 = words[i];
              string word2 = words[i+1];
              
              int len = min(word1.length(), word2.length());
              
              // keeps track if matched or not
              bool match = true;
              
              for(int j=0; j<len; j++){
                  // if word1 word2 dont match at jth posn it means that word1[j] comes before word2[j], so we add a directed edge between word1[j] -> word2[j]
                  if(word1[j] != word2[j]){
                      adj[word1[j]-'a'].push_back(word2[j]-'a');
                      // if doesnt match then false 
                      match = false;
                      // get out of the loop
                      break;
                  }
              }
              // if the words matched each other, then test if a larger word is coming before the smaller word, example: abcd abc, shows d comes before blank, which is wrong
              if(match && word1.size() > word2.size()){
                  return "";
              }
          }
          
          
          // to count the unique characters we might miss out on example if abc, abcd is there, we mgiht miss out on d
          unordered_set<char> uniqueChars;
          for(string word: words){
              for(char c: word){
                  uniqueChars.insert(c);
              }
          }
          
          stack<int>st;
          vector<int>visited(26, 0);
          // topo sort on this adj
          for(char i: uniqueChars){
              if(!visited[i-'a']){
                  if(topoSortDFS(i - 'a', adj, visited, st)){
                      return "";
                  }
              }
          }
          
          string ans;
          
          while(!st.empty()){
              ans.push_back(st.top()+'a');
              st.pop();
          }
          
          return ans;   
      }
  };