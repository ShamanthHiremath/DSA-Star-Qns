/*
1781. Sum of Beauty of All Substrings

https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.
 

Example 1:
Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.

Example 2:
Input: s = "aabcbaa"
Output: 17
*/

class Solution {
public:
    int beautySum(string s) {
        int n = s.length();

        int count = 0;

        for(int i=0; i<n; i++){
            unordered_map<char, int> freq;
            for(int j=i; j<n; j++){
                freq[s[j]]++;

                int mini  = INT_MAX;
                int maxi = INT_MIN;

                for(auto it = freq.begin(); it != freq.end(); ++it){
                    maxi = max(maxi, it->second);
                    mini = min(mini, it->second);
                }

                count += (maxi - mini);
                
            }
        }

        return count;
    }
};