/*
1838. Frequency of the Most Frequent Element

https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/

The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.

Example 1:

Input: nums = [1,2,4], k = 5
Output: 3
Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.
Example 2:

Input: nums = [1,4,8,13], k = 5
Output: 2
Explanation: There are multiple optimal solutions:
- Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
- Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
- Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.
Example 3:

Input: nums = [3,9,6], k = 2
Output: 1
*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        long long int left=0, right=0, ans=0, windowsum=0;

        while(right<nums.size()){
            // add new window elements
            windowsum += nums[right];

            // remove elements that cant be turned into the max freq value for that window
            // if a window sum + k (the number of times u can increase any element in that window by 1) is lesser than the highest element times the range of the window, then we can increase the no of elements,
            // if not we'll decrease the window size from left and remove elements
            while(left<nums.size() && (nums[right] *  (right-left+1) > windowsum + k) ){
                windowsum -= nums[left];
                left++;
            }

            ans = max(ans,  right-left+1);
            right++;
        }

        return ans;
    }
};