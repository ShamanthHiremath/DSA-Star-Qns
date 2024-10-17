/*
801. Minimum Swaps To Make Sequences Increasing

https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/

You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].

For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated so that the given input always makes it possible.

An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].

 

Example 1:

Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
Output: 1
Explanation: 
Swap nums1[3] and nums2[3]. Then the sequences are:
nums1 = [1, 3, 5, 7] and nums2 = [1, 2, 3, 4]
which are both strictly increasing.

Example 2:

Input: nums1 = [0,4,4,5,9], nums2 = [0,1,6,8,10]
Output: 1
Explanation:
Swap nums1[1] and nums2[1].
*/

class Solution {
public:
    int solveDP(int index, vector<int>& nums1, vector<int>& nums2, bool swapped, vector<vector<int>>&dp){
        if(index == nums1.size()){
            return 0;
        }
        if(dp[index][swapped] != -1){
            return dp[index][swapped];
        }
        // 1,3,5,4
        // 1,2,3,7
        int prev1 = nums1[index - 1];  // Previous element of nums1
        int prev2 = nums2[index - 1];  // Previous element of nums2

        if (swapped) {
            swap(prev1, prev2);  // If swapped, take the swapped values
        }

        int ans = INT_MAX;

        // Case 1: Don't swap at the current index
        if (nums1[index] > prev1 && nums2[index] > prev2) {
            ans = solveDP(index + 1, nums1, nums2, false, dp);  // No swap, continue
        }

        // Case 2: Swap at the current index
        if (nums1[index] > prev2 && nums2[index] > prev1) {
            ans = min(ans, 1 + solveDP(index + 1, nums1, nums2, true, dp));  // Swap, add 1 to the swap count
        }

        return dp[index][swapped] = ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        int n = nums1.size();

        vector<vector<int>>dp(n+1, vector<int>(2,-1));
        bool swapped  = false;
        return solveDP(1, nums1, nums2, swapped, dp);
    }
};