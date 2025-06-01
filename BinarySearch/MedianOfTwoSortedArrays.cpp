/*
4. Median of Two Sorted Arrays

https://leetcode.com/problems/median-of-two-sorted-arrays/

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).


Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

*/

class Solution {
public:
    // small and bigg indicate the array in terms of the size 
    double solve(vector<int>& small, vector<int>& big){
        int totalsize = small.size() + big.size();

        // the index occurence of median
        int medianInd = totalsize/2;

        // elementContriBySmallArr is in range 0 to small.size(), so do binary seeach on that
        int low = 0, high = small.size();

        while(low <= high){
            int partition = low + (high - low)/2;

            // Ensure valid indexing (handling partition edge cases)
            // l1, r1 inidcate the elements on the left and right of parittion of SMALL
            int l1 = (partition == 0) ? INT_MIN : small[partition - 1];
            int r1 = (partition == small.size()) ? INT_MAX : small[partition];

            // l2, r2 inidcate the elements on the left and right of parittion of BIG
            int l2 = (medianInd - partition == 0) ? INT_MIN : big[medianInd - partition - 1];
            int r2 = (medianInd - partition == big.size()) ? INT_MAX : big[medianInd - partition];

            // check for validity
            // the condition is that the l1, l2, belong to the LEFT MOST SIDE OF THE SORTED ARRAY IF MERGED, 
            // r1, r2, belong to the RIGHT MOST SIDE OF THE SORTED ARRAY IF MERGED,
            // so if they need to be right.... they have to follow the below checks

            // FOUND THE MEDIAN PARTITION
            if(l1 <= r2 and l2 <= r1){
                double median = 0;
                
                // if mergeed array total size is even, totalsize%2 == 0
                if(!(totalsize & 1)){
                    median = double ( (max(l1, l2) + min(r1, r2)) / 2.0 );
                }
                else{
                    median = min(r1, r2);
                }
                return median;
            }
            // 
            else if(l1 > r2){
                // the leftmost element from small, is greater than rightmost from big
                // which means the left side small arr elements can be pushed to right side of partiion
                // so we shorten the partition space
                high = partition - 1;
            }
            else if(l2 > r1){
                // the rightmost element from small, is smaller than leftmost from big
                // which means the right side small arr elements can be pushed to left side of partiion
                // so we increase the partition space
                low = partition + 1;
            }

        }

        return 0;

    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 <= n2){
            return solve(nums1, nums2);
        }
        else{
            return solve(nums2, nums1);
        }
    }
};