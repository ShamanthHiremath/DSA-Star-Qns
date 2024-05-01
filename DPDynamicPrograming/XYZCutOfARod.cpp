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

int cutSegments(int n, int x, int y, int z) {

	vector<int>dp(n+1, -1);
	int ans = dpSolve(n, x, y, z, dp);
	if(ans < 0){
		return 0; 
	}
	return ans;
}