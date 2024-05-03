class Solution{
	public:
	
	int solveDPTab(int n){
	    vector<int>dp(n+1, 0);
	    dp[0]=0;
	    dp[1]=1;
	    
	    for(int i=1; i<=n; i++){
	        int ans=i;
	        for(int j=1; j*j<=n; j++){
	            if(i - j*j >=0){
	                ans = min(ans, 1+ dp[i-j*j]);
	            }
	        }
	        dp[i] = ans;
	    }
	    
	    return dp[n];
	    
	}
	
	int solveDPMemo(int n, vector<int>&dp){
	    if(n==0){
	        return 0;
	    }
	    if(dp[n] != -1){
	        return dp[n];
	    }
	    int ans=n;
	    for(int i=1; i*i<=n; i++){
	        ans = min(ans, 1 + solveDPMemo(n-(i*i), dp));
	    }
	    dp[n] = ans;
	    return dp[n];
	}
	
	int MinSquares(int n)
	{
	    vector<int>dp(n+1, -1);
	    return solveDPTab(n);
	}
};