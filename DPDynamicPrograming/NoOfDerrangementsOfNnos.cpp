#include<limits.h>
#include<vector>
#define MOD 1000000007

long long int solveDP(int n, vector<long long int>&dp){
    if(n<=0){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }

    dp[n] = ( (n-1)%MOD * (solveDP(n-1, dp)%MOD + solveDP(n-2, dp)%MOD) )%MOD;

    return dp[n];
}

long long int solveDPTab(int n){
    if(n<=0){
        return 0;
    }
    if(n==2){
        return 1;
    }
    vector<long long int>dp(n+1, 0);
    // dp[1] = 0; already done
    dp[2] = 1;

    for(int i=3; i<=n; i++){
        dp[i] = ( (i-1)%MOD * (dp[i-1]%MOD + dp[i-2]%MOD) )%MOD;
    }
    return dp[n];

}

long long int countDerangements(int n) {
    if(n==1){
        return 0;
    }
    vector<long long int>dp(n+1, -1);
    long long int ans = solveDPTab(n);
    if(ans >= LLONG_MAX){
        return ans % MOD;
    }
    return ans;
}