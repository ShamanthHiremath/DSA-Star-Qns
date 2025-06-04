/*
992. Subarrays with K Different Integers

https://leetcode.com/problems/subarrays-with-k-different-integers/https://leetcode.com/problems/subarrays-with-k-different-integers/

Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.
 

Example 1:
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

Example 2:
Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
*/

class Solution {
public:
    int kDistinctChars(int k, vector<int>& s){
        if(k == 0){
            return 0;
        }
        int n = s.size();
        int cnt = 0;
        int l=0, r=0;

        unordered_map<int, int>mp;

        while(r<n){
            mp[s[r]]++;

            while(l<n && mp.size() > k){
                mp[s[l]]--;
                if(mp[s[l]] == 0){
                    mp.erase(s[l]);
                }
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }

        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // CORRECT K EQUALS TO (ATMOST K) - (ATMOST K-1)
        return kDistinctChars(k, nums) - kDistinctChars(k-1, nums);
    }
};