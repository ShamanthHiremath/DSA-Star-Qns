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