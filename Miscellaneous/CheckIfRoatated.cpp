class Solution {
public:
    bool check(vector<int>& nums) {
        int check=0;
        for(int  i=0; i<nums.size();i++){
            if(nums[i%nums.size()]>nums[(i+1)%nums.size()])check++;
        }
        if(check==0||check==1)return true;
        else return false;

        
    }
};
// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].