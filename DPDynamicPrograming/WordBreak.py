'''
139. Word Break

https://leetcode.com/problems/word-break/

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

'''


class Solution(object):
    
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """

        if len(s) == 0:
            return True
        
        for i in range(1, len(s)+1):
            if s[:i] in wordDict:
                if self.wordBreak(s[i:], wordDict):
                    return True
        
        return False
            

class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        # creating a  dp array of the size len(s) 
        # the first index (0) True, would denote the list taht would reflect an empty string would return be True
        dp = [True] + [False] * len(s)
        # now we iterate (i) through the string's indices, to check if there is a previous index (i - len(word) in wordDict to check if the word exists or not)
        for i in range(0, len(s)+1):
            for word in wordDict:
                prevIndexWordStart = i - len(word)
                # if the word index is in bound, and if the dp marking is true, and the substring from prevIndexWordStart: i is same as word, then mark as true
                if prevIndexWordStart >= 0 and dp[prevIndexWordStart] == True and s[prevIndexWordStart: i] == word:
                    dp[i] = True
                    break
        

        return dp[-1]


        