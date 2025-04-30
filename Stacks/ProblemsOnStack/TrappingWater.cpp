/*
42. Trapping Rain Water

https://leetcode.com/problems/trapping-rain-water/

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
*/
class Solution {
    public:
        int trap(vector<int>& height) {
            // CHECK FOR THAT BLOCK ONLY, THE UNITS OF WATER STORED IN THAT BLOCK.INDX
            //  For each index, we have to find the amount of water that can be stored and we have to sum it up.
            // If we observe carefully the amount the water stored at a particular index is the minimum of maximum elevation to the left and right of the index minus the elevation at that index.
            int n = height.size();
            // vector storing maximums to the left including itself
            vector<int>prefixMaxi(n);
            // vector storing maximums to the right including itself
            vector<int>suffixMaxi(n);
            
            prefixMaxi[0] = height[0];
            for(int i=1; i<n; i++){
                prefixMaxi[i] = max(prefixMaxi[i-1], height[i]);
            }
    
            suffixMaxi[n-1] = height[n-1];
            for(int i=n-2; i>=0; i--){
                suffixMaxi[i] = max(suffixMaxi[i+1], height[i]);
            }
    
    
            int totalUnits = 0;
            for(int i=0; i<n; i++){
                // for each block/index the units of water stored at that klevel is
                totalUnits += min(prefixMaxi[i], suffixMaxi[i]) - height[i];
            }
    
            return totalUnits;
    
    
        }
    };