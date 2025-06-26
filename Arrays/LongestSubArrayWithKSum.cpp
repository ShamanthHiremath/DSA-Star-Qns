/*
Longest Subarray with Sum K

https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

Examples:

Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
Output: 6
Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.

Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
Output: 5
Explanation: Only subarray with sum = -5 is [-5, 8, -14, 2, 4] of length 5.

Input: arr[] = [10, -10, 20, 30], k = 5
Output: 0
Explanation: No subarray with sum = 5 is present in arr[].
*/

class Solution {
  public:
    int longestSubarray(vector<int>& A, int K) {
        // code here
        int n = A.size();
        int i=0;
        int len = 0;
        
        int sum = 0;
        
        unordered_map<int, int>mp;
        
        while(i<n){
            sum += A[i];
            
            // if the sum at that index is K, then len = i+1;
            if(sum == K){
                len = i+1;
            }
            
            else{
                // finding if there exists a subarray on the left side in the MAP, that has x = sum - K with index mp[sum-k], 
                // such that we can consider the subarry after that, to get sum == k, since sum - x = K 
                if(mp.find(sum - K) != mp.end()){
                    len = max(len, i - mp[sum-K]);
                }
                // else just cache it in Map
                else{
                    mp[sum] = i;
                }
            }
            i++;
        }
        
        return len;
    }
};