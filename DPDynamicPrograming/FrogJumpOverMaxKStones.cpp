/*
Minimal Cost

https://www.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost

There is an array arr of heights of stone and Geek is standing at the first stone and can jump to one of the following: Stone i+1, i+2, ... i+k stone, where k is the maximum number of steps that can be jumped and cost will be |hi-hj| is incurred, where j is the stone to land on. Find the minimum possible total cost incurred before the Geek reaches the last stone.

Example:
Input: k = 3, arr[]= [10, 30, 40, 50, 20]
Output: 30
Explanation: Geek will follow the path 1->2->5, the total cost would be | 10-30| + |30-20| = 30, which is minimum

Input: k = 1, arr[]= [10, 20, 10]
Output: 20
Explanation: Geek will follow the path 1->2->3, the total cost would be |10 - 20| + |20 - 10| = 20.
*/

class Solution {
  public:
    int solveDP(int index, int k, vector<int>&dp, vector<int>&arr){
        if(index>=arr.size()-1){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        
        int mini=INT_MAX;
        for(int i=index+1; i<arr.size()&& i<=index+k ; i++){
            mini = min(mini, abs(arr[index] - arr[i]) + solveDP(i, k, dp, arr));
        }
        
        return dp[index] = mini;
    }
    
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        
        vector<int>dp(arr.size(), -1);
        return solveDP(0, k, dp, arr);
        // return mini;
    }
};