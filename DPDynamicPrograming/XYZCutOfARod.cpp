#include<limits.h>

int dpSolve(int  n, int x, int  y, int z, vector<int>&dp){
	if(n<0){
		return INT_MIN;
	}
	if(n==0){
		return 0;
	}
	if(dp[n] != -1){
		return dp[n];
	}

	int xcut = dpSolve(n-x, x, y, z, dp) + 1;
	int ycut = dpSolve(n-y, x, y, z, dp) + 1;
	int zcut = dpSolve(n-z, x, y, z, dp) + 1;

	dp[n] = max(xcut, max(ycut, zcut));

	return dp[n];

}

int solveTab(int n, int x, int y, int z){
	vector<int>dp(n+1, -1);
	dp[0]=0;

	for(int i=1; i<=n; i++){
		if(i - x>=0 && dp[i-x] != -1){
			dp[i] = max(dp[i], dp[i-x] + 1); 
		}
		if(i - y>=0 && dp[i-y] != -1){
			dp[i] = max(dp[i], dp[i-y] + 1); 
		}
		if(i - z>=0 && dp[i-z] != -1){
			dp[i] = max(dp[i], dp[i-z] + 1); 
		}
	}
	if(dp[n]<0){
		return 0;
	}
	else
		return dp[n];
}

int cutSegments(int n, int x, int y, int z) {

	vector<int>dp(n+1, -1);
	int ans = dpSolve(n, x, y, z, dp);
	if(ans < 0){
		return 0; 
	}
	return ans;
}