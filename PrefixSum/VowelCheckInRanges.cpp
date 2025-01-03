/*
2559. Count Vowel Strings in Ranges

https://leetcode.com/problems/count-vowel-strings-in-ranges/description/

You are given a 0-indexed array of strings words and a 2D array of integers queries.
Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.
Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

Example 1:
Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]
Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
The answer to the query [0,2] is 2 (strings "aba" and "ece").
to query [1,4] is 3 (strings "ece", "aa", "e").
to query [1,1] is 0.
We return [2,3,0].

Example 2:
Input: words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
Output: [3,2,1]
Explanation: Every string satisfies the conditions, so we return [3,2,1].
*/

class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>prefix(n+1, 0);
        // n+1 handles empty string case also
        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i];
            if(isVowel(words[i].front()) && isVowel(words[i].back())){
                prefix[i+1]++;
            }
        }



        vector<int>ans;

        for(auto query: queries){
            int left = query[0];
            int right = query[1];

            ans.push_back(prefix[right+1] - prefix[left]);
        }

        return ans;
    }
};