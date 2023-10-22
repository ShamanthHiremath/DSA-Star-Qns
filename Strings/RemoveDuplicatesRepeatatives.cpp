// class Solution {
// public:
//     string removeDuplicates(string s1) {
//         int i=0;
//         while(i<s1.size()){
//             if(s1[i]==s1[i+1]){
//                 s1.erase(i,2);
//                 i=-1;
//             }
//             i++;
//         }
//         return s1;
             
//     }
// };
class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for (int i = 0; i < s.length(); i++)
        {
            if (!ans.empty() && ans.back() == s[i])
                ans.pop_back();
            else
                ans.push_back(s[i]);
        }
        return ans;
    }
};