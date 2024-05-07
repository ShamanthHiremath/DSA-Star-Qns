/*
Input: n = 3, m = 6
mat = {            Len = 3
        {1, 1, 0, |1, 1, 1|}, 
       {1, 1, 0, |1, 1, 1|}
       {1, 1, 0, |1, 1, 1|}
    }
Output: 3
*/
class Solution{
public:
    
    int solve(vector<vector<int>>&mat, int i, int j, int &maxi, vector<vector<int>> &dp){
        if(i >= mat.size() || j >= mat[0].size()){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int right = solve(mat, i, j+1, maxi, dp);
        int diagonal = solve(mat, i+1, j+1, maxi, dp);
        int down = solve(mat, i+1, j, maxi, dp);
        
        if(mat[i][j] == 1){
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return dp[i][j] = ans;
        }
        else{
            return dp[i][j] = 0;
        }
    }
    
    int solveTab(vector<vector<int>>&mat, int &maxi){
        vector<vector<int>> dp(mat.size() + 1, vector<int>(mat[0].size() + 1, 0));
        // dp[n-1][m-1] = 0;
        
        for(int i = mat.size()-1; i >= 0; i--){
            for(int j = mat[0].size() - 1; j >= 0; j--){
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];
                
                if(mat[i][j] == 1){
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // int maxi = 0;
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // int ans = solve(mat, 0, 0, maxi, dp);
        // return maxi;
        int maxi = 0;
        solveTab(mat, maxi);
        return maxi;
    }
};