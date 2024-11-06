/*
Example 1:
Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".

Example 2:
Input: s = "ababab"
Output: "abab"
Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.

*/
class Solution {
public:
    string longestPrefix(string s) {
        vector<int> pi(s.size(), 0);
        int i = 1;
        int len = 0;
        //pi[0] = 0;

        while (i != s.size()) {
            if (s[i] == s[len]) {
                len++;
                pi[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = pi[len - 1];
                }
                else {
                    pi[i] = 0;
                    i++;
                }
            }
        }
        int size = pi[s.size()-1];
        return s.substr(0, size);
    }
};
