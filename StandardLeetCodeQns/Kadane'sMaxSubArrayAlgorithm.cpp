/*
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxisum=nums[0];
        int currsum=0;
        //sliding windows
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            maxisum=max(maxisum, currsum);
            if(currsum<0)currsum=0;
        }
        return maxisum;
    }
};