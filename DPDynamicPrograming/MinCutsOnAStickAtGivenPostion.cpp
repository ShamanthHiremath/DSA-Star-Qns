/*
1547. Minimum Cost to Cut a Stick

https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:
Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.


Example 1:
Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:
The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).

Example 2:
Input: n = 9, cuts = [5,6,1,4,2]
Output: 22
Explanation: If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.
*/

class Solution {
    public:
        long long solveDP(int start, int end, vector<int>& cuts, vector<vector<long long>>&dp){
            // no more cost, one sized array
            if(start > end){
                return 0;
            }
    
            if(dp[start][end] != -1){
                return dp[start][end];
            }
    
            long long ans = 10e9;
    
            for(int i=start; i<=end; i++){
                long long take = cuts[end+1] - cuts[start-1] + solveDP(i+1, end, cuts, dp) + solveDP(start, i-1, cuts, dp);
                ans = min(ans, take);
            }
    
            return dp[start][end] = ans;
        }
        int minCost(int n, vector<int>& cuts) {
            cuts.push_back(0);
            cuts.push_back(n);
            sort(cuts.begin(), cuts.end());
    
            int c = cuts.size();
            vector<vector<long long>> dp(c, vector<long long >(c, -1));
    
            return solveDP(1, c-2, cuts, dp);

            // BOTTOM UP APPROACH DP

            // Add the boundaries (0 and n)
            vector<int> cutPoints = {0};
            cutPoints.insert(cutPoints.end(), cuts.begin(), cuts.end());
            cutPoints.push_back(n);
            
            int m = cutPoints.size();
            vector<vector<int>> dp(m, vector<int>(m, 0));
            
            // Fill the DP table
            for (int length = 2; length < m; ++length) {
                for (int i = 0; i + length < m; ++i) {
                    int j = i + length;
                    dp[i][j] = INT_MAX;
                    for (int k = i + 1; k < j; ++k) {
                        dp[i][j] = min(dp[i][j], cutPoints[j] - cutPoints[i] + dp[i][k] + dp[k][j]);
                    }
                }
            }
            
            return dp[0][m - 1];
        }
    };