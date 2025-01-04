/*
451. Sort Characters By Frequency

https://leetcode.com/problems/sort-characters-by-frequency/description/

Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them.

Example 1:
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:
Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>freq;
        for(char ch: s){
            freq[ch]++;
        }
        auto cmp = [](pair<char, int>&a, pair<char, int>&b){
            return a.second < b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char,int>>, decltype(cmp)>pq;

        for(auto fr: freq){
            pq.push({fr.first, fr.second});
        }

        string ans = "";
        while(!pq.empty()){
            // append(n, char) append adds a single char n times 
            ans.append(pq.top().second, pq.top().first);
            pq.pop();
        }

        return ans;

    }
};