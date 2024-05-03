#include <bits/stdc++.h> 

int solveDPMemo(vector<int> &num, int tar, vector<int>&dp){
    if(tar<0){
        return 0;
    }
    if(tar==0){
        return 1;
    }
    if(dp[tar]!=-1){
        return dp[tar];
    }
    int ans=0;
    //because each element in nums (n) is tried tar times and 
    for(int i=0; i<num.size(); i++){
        ans += solveDPMemo(num, tar-num[i], dp);
    }

    return dp[tar] = ans;
}

int solveDPTab(vector<int> &num, int tar){
    vector<int>dp(tar+1, 0);
    dp[0]=1;

    int ans=0;
    //filler for dp array
    for(int i=1; i<=tar; i++){
        //recursion step for traversing the num vector
        for(int j=0; j<num.size(); j++){
            if(i-num[j]>=0){
                dp[i] += dp[i - num[j]];
            }
        }
    }
    return dp[tar];

}

int findWays(vector<int> &num, int tar)
{
    vector<int>dp(tar+1, -1);
    return solveDPTab(num, tar);
}