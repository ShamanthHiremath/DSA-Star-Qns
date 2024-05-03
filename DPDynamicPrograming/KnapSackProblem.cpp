/*
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.
*/
#include <bits/stdc++.h>

int solveDP(vector<int>&weight, vector<int>&value, int index, int capacityInKS, vector<vector<int>>&dp){
	//base case
	if(index==0){
		if(weight[0] <= capacityInKS){
			return value[0];
		}
		else{
			return 0;
		}
	}

	if(dp[index][capacityInKS] != -1){
		return dp[index][capacityInKS];
	}

	int incl = 0;
	if(weight[index] <= capacityInKS){
		incl = value[index] + solveDP(weight, value, index-1, capacityInKS-weight[index], dp);
	}
	int excl = 0 + solveDP(weight, value, index-1, capacityInKS, dp);

	return dp[index][capacityInKS] = max(incl, excl);
}

int solveDPTab(vector<int>&weight, vector<int>&value, int n, int capacityInKS){
	//Step 1: Create dp array
	vector<vector<int>>dp(n, vector<int>(capacityInKS+1, 0));

	//Step 2: Analyse Base Case
	for(int w=weight[0] ; w<=capacityInKS; w++){
		if(weight[0] <= capacityInKS){
			dp[0][w] = value[0];
		}
	}

	for(int index=1; index<n; index++){
		for(int w=0; w<=capacityInKS; w++){
				int incl = 0;
				if(weight[index] <= w){
					incl = value[index] + dp[index-1][w-weight[index]];
				}
				int excl = 0 + dp[index-1][w];

				dp[index][w] = max(incl, excl);			
		}
	}

	return dp[n-1][capacityInKS];
	
}

int solveDPTabSpaceOptimised(vector<int>&weight, vector<int>&value, int n, int capacityInKS){
	//Step 1: Create dp array
	vector<int>prevDP(capacityInKS+1, 0);
	vector<int>currDP(capacityInKS+1, 0);

	//Step 2: Analyse Base Case
	for(int w=weight[0] ; w<=capacityInKS; w++){
		if(weight[0] <= capacityInKS){
			prevDP[w] = value[0];
		}
	}

	for(int index=1; index<n; index++){
		for(int w=0; w<=capacityInKS; w++){
				int incl = 0;
				if(weight[index] <= w){
					incl = value[index] + prevDP[w-weight[index]];
				}
				int excl = 0 + prevDP[w];

				currDP[w] = max(incl, excl);			
		}
		prevDP = currDP;
	}

	return prevDP[capacityInKS];
	
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n, vector<int>(maxWeight+1, -1));
	return solveDPTabSpaceOptimised(weight, value, n, maxWeight);
	// return solveDP(weight, value, n, maxWeight, dp);
}