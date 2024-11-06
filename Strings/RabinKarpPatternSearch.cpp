/*

WATCH THIS VIDEO TO UNDERSTAND THE RABIN KARP ALGORITHM
https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/

686. Repeated String Match

https://leetcode.com/problems/repeated-string-match/description/

Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

Example 1:

Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
Example 2:

Input: a = "a", b = "aa"
Output: 2
*/

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if(a == b){
            return 1;
        }
        string source = a;
        int appendcount = 1;
        while(source.size() < b.size()){
            source += a;
            appendcount++;
        }

        if(source == b){
            return appendcount;
        }
        else if(RabinKarp(source, b) != -1){
            return appendcount;
        }
        else if(RabinKarp(source + a, b) != -1){
            return appendcount + 1;
        }
        else{
            return -1;
        }
    }


    int RabinKarp(string text, string pattern){
        int base = 1000000;
        if(text == "" or pattern == ""){
            return -1;
        }

        int m = pattern.size();
        int power = 1;
        for(int i=0; i<m; i++){
            power = (power*31)%base;
        }

        int patternhash = 0;
        for(int i=0; i<m; i++){
            patternhash = (patternhash*31 + pattern[i])%base;
        }

        int hashcode = 0;
        for(int i=0; i<text.size(); i++){
            hashcode = (hashcode*31 + text[i])%base;
            if(i<m-1){
                continue;
            }
            if(i>=m){
                hashcode = (hashcode - text[i-m]*power)%base;
            }
            if(hashcode<0){
                hashcode += base;
            }
            if(hashcode == patternhash){
                if(text.substr(i-m+1, m) == pattern){
                    return i-m+1;
                }
            }
        }

        return -1;

    }
};