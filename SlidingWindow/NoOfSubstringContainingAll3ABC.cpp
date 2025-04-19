/*
1358. Number of Substrings Containing All Three Characters

https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

Example 1:
Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

Example 2:
Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:
Input: s = "abc"
Output: 1
*/
class Solution(object):
    def numberOfSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        abc_cnt = {'a': 0, 'b': 0, 'c': 0}
        # left and right pointers
        left = right = 0

        no_of_sub_str = 0

        for right in range(0, len(s)):
            abc_cnt[s[right]] += 1

            while abc_cnt['a']>0 and abc_cnt['b']>0 and abc_cnt['c']>0:
                # window satisfied so the substring btw left and right pointers satisfy, which also means that the substrings from left to end of the string also satsisfy, so we have length - right, as no of subsrtrings
                # Ex: abcabc, right is at 2, left is at 0, abc satsifies,, likewise abc, abca, abcab, abcabc also satsify
                no_of_sub_str += (len(s) - right)
                
                abc_cnt[s[left]] -= 1
                # move to next index, to check for more
                left += 1
        
        return no_of_sub_str

