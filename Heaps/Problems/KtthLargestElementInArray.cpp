/*
215. Kth Largest Element in an Array

https://leetcode.com/problems/kth-largest-element-in-an-array/description/

Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting?

Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;

        for(int num:nums){
            pq.push(num);
        }

        for(int i=0; i<k-1; i++){
            pq.pop();
        }

        return pq.top();
    }
};