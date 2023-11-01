class Solution {
private: 
    void solve (vector<vector<int>>& ans, vector<int> output,vector<int>nums, int index){
        //base condition
        if(index>=nums.size()){
            ans.push_back(output);
            return ;
        }
        //exclusion
        solve(ans, output, nums, index+1);

        //inclusion
        output.push_back(nums[index]);
        solve(ans, output, nums, index+1);
    }

public:
    vector<vector<int>> subsets (vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>output;
        int index=0;
        solve(ans, output, nums, index);
        return ans;
    }
};