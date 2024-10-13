/*
Dice throw

https://www.geeksforgeeks.org/problems/dice-throw5349/1

Given n dice each with m faces. Find the number of ways to get sum x which is the summation of values on each face when all the dice are thrown.

Example:

Input: m = 6, n = 3, x = 12
Output: 25
Explanation: There are 25 total ways to get the Sum 12 using 3 dices with faces from 1 to 6.
Input: m = 2, n = 3, x = 6
Output: 1
Explanation: There is only 1 way to get the Sum 6 using 3 dices with faces from 1 to 2. All the dices will have to land on 2.

*/
class Solution {
  public:
  
    long long solveDP(int face, int target, int dice, vector<vector<long long int>>&dp){
        if(target < 0){
            return 0;
        }
        if(target == 0 &&  dice == 0){
            return 1;
        }
        if(target == 0 && dice != 0){
            return 0;
        }
        if(target != 0 && dice == 0){
            return 0;
        }
        
        if(dp[dice][target] != -1){
            return dp[dice][target];
        }
        
        long long ways = 0;
        for(int i=1; i<=face; i++){
            ways += solveDP(face, target-i, dice-1, dp);
        }
        
        return dp[dice][target] = ways;
    }
    
    long long solveTab(int m, int n, int x){
        vector<vector<long long int>>dp(n+1,  vector<long long int>(x +1 , 0));
        //base case
        dp[0][0] = 1;

        // ***********************************************************************************
        // Can be optimised by  using previous and current rows only
        // ***********************************************************************************
        
        for(int dice=1; dice<=n; dice++){
            for(int target=1; target<=x; target++){
                long long ways = 0;
                for(int i=1; i<=m; i++){
                    if(target - i >= 0){
                        ways += dp[dice-1][target-i];
                    }
                }
                
                dp[dice][target] = ways;
            }
        }
        
        return dp[n][x];
    }
    
    long long noOfWays(int m, int n, int x) {
        // code here
        vector<vector<long long int>>dp(n+1,  vector<long long int>(x +1 , -1));
        
        // return solveDP(m, x, n, dp);
        return solveTab(m,n, x);
    }
};