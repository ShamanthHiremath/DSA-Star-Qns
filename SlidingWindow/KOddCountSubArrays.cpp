/*
1248. Count Number of Nice Subarrays

https://leetcode.com/problems/count-number-of-nice-subarrays/description/

Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.


Example 1:
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

Example 2:
Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.

Example 3:
Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l=0, r=0;
        int n = nums.size();

        int niceArrCount = 0;
        int oddcount = 0;



        while(r<n){
            if(nums[r] & 1){
                oddcount++;
            }

            while(oddcount > k){
                if(nums[l] & 1){
                    oddcount--;
                }
                l++;
            }

            if (oddcount == k) {
                niceArrCount++;
                // Count all valid subarrays ending at `r`
                int temp = l;
                while (temp < r && nums[temp] % 2 == 0) {
                    niceArrCount++;
                    temp++;
                }
            }


            r++;

        }

        return niceArrCount;
    }
};