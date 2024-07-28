/*
Longest Increasing Subsequence

Given an array a[ ] of n integers, find the Length of the Longest Strictly Increasing Subsequence.

A sequence of numbers is called "strictly increasing" when each term in the sequence is smaller than the term that comes after it.

Return the length of the longest increasing subsequence.

Example 1:

Input: n = 6, a[ ] = {5,8,3,7,9,1}
Output: 3
Explanation: There are more than one LIS in this array.  
One such Longest increasing subsequence is {5,7,9}.
Example 2:

Input: n = 16, a[ ] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}
Output: 6
Explanation: There are more than one LIS in this array. 
One such Longest increasing subsequence is {0,2,6,9,13,15}.
*/


/*
TWO APPROACHES

DP INCL EXCL O(n^2)
Binary Search O(nlogn)
*/

class Solution{
private:
    int solveDP(int n, int arr[], int curr, int prev, vector<vector<int>>&dp){
        if(curr>=n){
            return 0;
        }
        
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        
        int incl = 0;
        if(prev == -1 || arr[curr] > arr[prev]){
            incl = 1 + solveDP(n, arr, curr+1, curr, dp);
        }
        int excl = 0 + solveDP(n, arr,curr+1, prev, dp);
        
        return dp[curr][prev+1] = max(incl, excl);
    }
    
    int solveTab(int n, int arr[]){
        vector<int>currrow(n+1, 0);
        vector<int>nextrow(n+1, 0);
        
        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int incl = 0;
                if(prev == -1 || arr[curr] > arr[prev]){
                    incl = 1 + nextrow[curr+1];
                }
                int excl = 0 + nextrow[prev+1];
                
                currrow[prev+1] = max(incl, excl);
            }
            nextrow = currrow;
        }
        
        return nextrow[0];
        
    }
    
    void insertinarr(int key, vector<int>&ans){
        int s = 0;
        int e = ans.size()-1;
        int mid = s + (e-s)/2;
        while(s<=e){
            if(ans[mid]>key){
                e = mid-1;
            }
            else if(ans[mid] == key){
                break;
            }
            else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        ans[mid] = key;
    }
    
    int binarysolve(int n, int arr[]){
        vector<int>ans;
        ans.push_back(arr[0]);
        for(int i=1; i<n; i++){
            if(ans[ans.size()-1]< arr[i]){
                ans.push_back(arr[i]);
            }
            else{
                int key = arr[i];
                insertinarr(key, ans);
            }
        }
        
        return ans.size();
    }
    
public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]){
       // your code here
    //   vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
    //   return solveDP(n, a, 0, -1, dp);
    
        // return solveTab(n, a);
        
        return binarysolve(n, a);
    }
};