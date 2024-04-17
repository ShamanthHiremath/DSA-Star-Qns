#include <bits/stdc++.h> 

int solveDPMemo(vector<int>nums, vector<int>dp, int i, int n){
    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int incl=solveDPMemo(nums, dp, i+2, n)+nums[i];
    int excl=solveDPMemo(nums, dp, i+1, n);

    dp[i]=max(incl, excl);
    return dp[i];
}

int solveDPTabu(vector<int>& nums){
    vector<int> dp(nums.size(), 0);
    
    if(nums.size() >= 1)
        dp[0] = max(0, nums[0]);
    if(nums.size() >= 2)
        dp[1] = max(dp[0], nums[1]);
    
    for(int i = 2; i < nums.size(); i++){
        int incl = dp[i - 2] + nums[i];
        int excl = dp[i - 1];
        dp[i] = max(incl, excl);
    }
    return dp[nums.size() - 1];
}

int maximumNonAdjacentSum(vector<int> &nums){
    return solveDPTabu(nums);
}
