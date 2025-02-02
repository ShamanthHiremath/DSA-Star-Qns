/*
Geek's Training

https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training

Geek is going for a training program for n days. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Given a 2D array arr[][] of size n where arr[i][0], arr[i][1], and arr[i][2] represent the merit points for Running, Fighting, and Learning on the i-th day, determine the maximum total merit points Geek can achieve .

Example:

Input: arr[]= [[1, 2, 5], [3, 1, 1], [3, 3, 3]]
Output: 11
Explanation: Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day he will do fighting and earn 3 points so, maximum merit point will be 11.

Input: arr[]= [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
Output: 6
Explanation: Geek can perform any activity each day while adhering to the constraints, in order to maximize his total merit points as 6.

Input: arr[]= [[4, 2, 6]]
Output: 6
Explanation: Geek will learn a new move to make his merit points as 6.
*/

class Solution {
  public:
    int solveDP(int day, int type, vector<vector<int>>& arr, vector<vector<int>>&dp){
        if(day>=arr.size()){
            return 0;
        }
        
        if(dp[day][type] != -1){
            return dp[day][type];
        }
        
        int maxPoints = 0;
        for (int nextType = 0; nextType < 3; ++nextType) {
            int points = 0;
            if (nextType != type) {
                points = arr[day][nextType];
            }
            maxPoints = max(maxPoints, points + solveDP(day + 1, nextType, arr, dp));
        }

        return dp[day][type] = maxPoints;
        
    }
  
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        vector<vector<int>>dp(n+1, vector<int>(4, -1));
        return solveDP(0, 3, arr, dp);
        
    }
};


class Solution {
  public:
    int solveDP(int day, int type, vector<vector<int>>& arr, vector<vector<int>>&dp){
        if(day>=arr.size()){
            return 0;
        }
        
        if(dp[day][type] != -1){
            return dp[day][type];
        }
        
        int maxPoints = 0;
        for (int nextType = 0; nextType < 3; ++nextType) {
            if (nextType != type) {
                maxPoints = max(maxPoints, solveDP(day + 1, nextType, arr, dp));
            }
        }

        return dp[day][type] = arr[day][type] + maxPoints;
        
    }
  
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        vector<vector<int>>dp(n+1, vector<int>(3, -1));
        return max({solveDP(0, 0, arr, dp), solveDP(0, 1, arr, dp), solveDP(0, 2, arr, dp)});
        
    }
};