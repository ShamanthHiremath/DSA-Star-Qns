/*
Encode and Decode Strings

https://www.geeksforgeeks.org/problems/encode-and-decode-strings/1

Given an array of strings s[], you are required to create an algorithm in the encode() function that can convert the given strings into a single encoded string, which can be transmitted over the network and then decoded back into the original array of strings. The decoding will happen in the decode() function.

You need to implement two functions:
1. encode(): This takes an array of strings s[] and encodes it into a single string. 
2. decode(): This takes the encoded string as input and returns an array of strings containing the original array as given in the encode method.

Note: You are not allowed to use any inbuilt serialize method.  

Examples:

Input: s = ["Hello","World"]
Output: ["Hello","World"]
Explanation: The encode() function will have the str as input, it will be encoded by one machine. Then another machine will receive the encoded string as the input parameter and then will decode it to its original form.
Input: s = ["abc","!@"]
Output: ["abc","!@"]
Explanation: The encode() function will have the str as input, here there are two strings, one is "abc" and the other one has some special characters. It will be encoded by one machine. Then another machine will receive the encoded string as the input parameter and then will decode it to its original form.

*/

class Solution {
  public:
    string encode(vector<string>& s) {
        // code here
        string ans;
        
        for(string strr: s){
            ans += strr;
            ans += '\0';
            // cout<<ans;
        }
        
        return ans;
    }

    vector<string> decode(string& s) {
        
        // code here
        vector<string> ans;
        int i=0;
        while(i<s.length()){
            string temp = "";
            while(i<s.length() and s[i] != '\0'){
                temp.push_back(s[i]);
                i++;
            }
            ans.push_back(temp);
            i++;
        }
        
        return ans;
    }
};