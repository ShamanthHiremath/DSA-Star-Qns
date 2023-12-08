/*
Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

if not return -1

Input=
haystack = "hello"
needle = "ll"
Output = 2
*/
class Solution {
public:
//creates a pi table which checks the prefix and suffix for each element in the given substring and stores the value of their lengths
//ex: ababab
//pi: 001234
    vector<int> longestPrefix(string s) {
        vector<int> pi(s.size(), 0);
        int i = 1;
        int len = 0;
        //pi[0] = 0;

        while (i != s.size()) {
            //first for a and b check
            //second for aba ie a and a equal.... prefix a suffix is also a,so increases len and i, stores len=1
            //third for abab ie b and b equal.....prefix is ab sufix is also ab, so increases len and i, stores len=2
            if (s[i] == s[len]) {
                len++;
                pi[i] = len;
                i++;
            }
            //not equal so will store 0
            //increase i
            else {
                //if they become unequal just do this i dont have no idea y is this done just do this
                if (len != 0) {
                    len = pi[len - 1];
                }
                //if len is 0 uuntill the first prefix and suffix is found 
                else {
                    pi[i] = 0;
                    i++;
                }
            }
        }
        return pi;
    }
    int strStr(string str, string sub) {
        int i=0;
        int len=0;
        vector<int> lps=longestPrefix(sub);
        while(i<str.size()){
            if(str[i]==sub[len]){
                i++;
                len++;
            }
            if(len==sub.size()){
                // cout<<"the sub string is found at index "<<i-len;
                return i-len;
            }
            else if(i<str.size() && str[i]!=sub[len]){
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    i++;
                }
            }
        }
        //substr not found
        return -1; 
    }
};