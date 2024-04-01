class Solution{

	public:
	
	int solve(int x, int n, vector<int>&dp, vector<int>&coins){
	    if(x==0){
	        return 0;
	    }
	    if(x<0){
	        return INT_MAX;
	        
	    }
	    // answer already memoed/stored
	    if(dp[x]!=-1){
	        return dp[x];
	    }
	    
	    int mini=INT_MAX;
	    for(int i=0; i<n; i++){
	        int ans=solve(x-coins[i], n, dp, coins);
	        if(ans!=INT_MAX){
	            mini=min(ans+1, mini);
	        }
	    }
	    //store the mini at that x value
	    dp[x]=mini;
	    return dp[x];
	    
	}
	
	
	int minCoins(vector<int> &coins, int M, int V) 
	{ 
	    vector<int>dp(V+1, -1);
	    int ans=solve(V, M, dp, coins);
	    if(ans!=INT_MAX){
	        return ans;
	    }
	    else{
	        return -1;
	    }
	}
};