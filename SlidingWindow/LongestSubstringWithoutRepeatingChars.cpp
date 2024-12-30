/*
3. Longest Substring Without Repeating Characters

https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

Given a string s, find the length of the longest 
substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        //SLIDING WINDOW  - TIME COMPLEXITY O(2n)
        //                  SPACE COMPLEXITY O(m)   //size of array
        
        int store[256]={0}; //array to store the occurences of all the characters
        int l=0;    //left pointer
        int r=0;    //right pointer
        int ans=0;  //initializing the required length as 0
        
        while(r<s.length())     //iterate over the string till the right pointer reaches the end of the string 
        {
            store[s[r]]++;
            // cout<<store[s[r]];      //increment the count of the character present in the right pointer 
            
            while(store[s[r]]>1)    //if the occurence become more than 1 means the char is repeated
            { 
                store[s[l]]--;
                // cout<<cout<<store[s[l]];   //reduce the occurence of temp as it might be present ahead also in the string
                l++;         //contraction of the present window till the occurence of the 't' char becomes 1
            }
            
            ans = max(ans,r-l+1);    //As the index starts from 0 , ans will be (right pointer-left pointer + 1)
            r++;        // now will increment the right pointer 
        }
        return ans;
    }
};