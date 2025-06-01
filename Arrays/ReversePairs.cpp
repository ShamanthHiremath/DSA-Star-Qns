/*
493. Reverse Pairs

https://leetcode.com/problems/reverse-pairs/

Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
 

Example 1:
Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1


Example 2:
Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
*/
class Solution {
public:
    void merge(int s, int mid, int e, vector<int>&nums){
        vector<int>temp;

        int left=s;
        int right=mid+1;

        while(left <= mid && right <= e){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= e){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i = s; i <= e; i++){
            nums[i] = temp[i - s];
        }

    }
    // u always get sorted here, so check the conditions
    int countPairs(int s, int mid, int e, vector<int>&nums){
        int count = 0;

        int right = mid+1;

        // here we get two sorted arrays, s to mid, and mid+1 to e
        for(int left=s; left<=mid; left++){
            while(right <= e && float(nums[left])/2.0 > nums[right]){
                right++;
            }
            // since those numbers on the right of the pointer untill mid+1, are already
            // twice greateert than 
            count += (right - (mid+1));
        }

        return count;

    }

    int mergeSort(int s, int e, vector<int>&nums){
        if(s>=e){
            return 0;
        }
        
        int count = 0;
        int mid = s + (e-s)/2;
        
        count += mergeSort(s, mid, nums);
        count += mergeSort(mid+1, e, nums);
        
        count += countPairs(s, mid, e, nums);

        merge(s, mid, e, nums);

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(0, nums.size()-1, nums);
    }
};