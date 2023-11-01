class Solution {
private:
    void solve(string mapp[], string digits, string output,vector<string>& ans, int index){
        if(index>=digits.size()){
            ans.push_back(output);
            return ;
        }
        int digitnum =digits[index]-'0';
        string separated= mapp[digitnum];
        for(int i=0; i<separated.size();i++){
            output.push_back(separated[i]);
            solve(mapp, digits, output, ans, index+1);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0)return ans;
        string output="";
        string mapp[10] = {"", "", "abc","def", "ghi", "jkl", "mno","pqrs", "tuv", "wxyz"};
        int index=0;
        solve(mapp, digits, output, ans, index);
        return ans;
    }
};
