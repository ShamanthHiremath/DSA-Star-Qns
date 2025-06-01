/*
Count Inversions

https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

Counting inversions means determining the number of pairs (i, j) such that i < j and nums[i] > nums[j].
Here's the corrected implementation:

Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.
Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.




*/

class Solution {
public:
    void merge(int s, int mid, int e, vector<int>& nums, int& count) {
        vector<int> temp;
        int left = s, right = mid + 1;

        // Counting inversions while merging sorted halves
        while (left <= mid && right <= e) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                count += (mid - left + 1); // Elements left in left half are greater
                right++;
            }
        }

        // Copy remaining elements from left half
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        // Copy remaining elements from right half
        while (right <= e) {
            temp.push_back(nums[right]);
            right++;
        }

        // Copy merged elements back to original array
        for (int i = s; i <= e; i++) {
            nums[i] = temp[i - s];
        }
    }

    int mergeSort(int s, int e, vector<int>& nums) {
        if (s >= e) return 0;

        int count = 0;
        int mid = s + (e - s) / 2;

        // Recursively count inversions in left and right halves
        count += mergeSort(s, mid, nums);
        count += mergeSort(mid + 1, e, nums);

        // Merge both halves and count cross-inversions
        merge(s, mid, e, nums, count);

        return count;
    }

    int countInversions(vector<int>& nums) {
        return mergeSort(0, nums.size() - 1, nums);
    }
};