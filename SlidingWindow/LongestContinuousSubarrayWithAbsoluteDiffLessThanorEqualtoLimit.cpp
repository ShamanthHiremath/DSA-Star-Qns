// Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
/*
Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.

*/


// class Solution {
// public:
//     int longestSubarray(vector<int>& nums, int limit) {
//         int n = nums.size();
//         // int ans = 0;
//         // int i = 0, j = 0;
//         // while(i != n){
            
//         // }
//         int len = 0;

//         for(int i=0; i<n; i++){
//             int maxi = nums[i];
//             int maxiInd = i;
//             int mini = nums[i];
//             int miniInd = i;
//             for(int j=i; j<n; j++){
//                 if(nums[j]> maxi){
//                     maxi = nums[j];
//                     maxiInd = j;
//                 }
//                 else if(nums[j]<mini){
//                     mini = nums[j];
//                     miniInd = j;
//                 }
//                 if(maxi - mini <= limit){
//                     len = max(j-i + 1, len);
//                 }
//             }
//         }

//         return len;

//     }
// };

#include <deque>
#include <vector>
#include <algorithm>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums, int limit) {
        std::deque<int> maxDeque, minDeque;
        int left = 0;
        int result = 0;

        for (int right = 0; right < nums.size(); ++right) {
            // Maintain the decreasing order maxDeque
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);

            // Maintain the increasing order minDeque
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right);

            // If the current window is invalid, move the left pointer
            while (nums[maxDeque.front()] - nums[minDeque.front()] > limit) {
                if (maxDeque.front() == left) maxDeque.pop_front();
                if (minDeque.front() == left) minDeque.pop_front();
                ++left;
            }

            // Update the result
            result = std::max(result, right - left + 1);
        }

        return result;
    }
};
