class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        if(nums.size()<4)return ans;
        sort(nums.begin(), nums.end());
        //int i=0;
        for(int i=0; i<nums.size()-3;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1; j<nums.size()-2; j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                int left=j+1, right=nums.size()-1;
                while(left<right){
                    // long long int sum=nums[i]+nums[j]+nums[left]+nums[right];
                    //by writing below 4 statement this way it will not give runtime error
                    long long int sum = nums[i];
                    sum += nums[j];
                    sum += nums[left];
                    sum += nums[right];
                    // long long int sum = static_cast<long long int>(nums[i]) + nums[j] + nums[left] + nums[right];
                    if(sum>target){
                        right--;
                    }
                    else if(sum==target){
                        cout<<nums[i]<< nums[j]<<nums[left]<< nums[right]<< "   ";
                        ans.push_back({nums[i], nums[j],nums[left], nums[right]});
                    //set.insert({nums[i], nums[j],nums[k]});
                    //skips the necessity for this 
                    //skip duplicates
                        while (left < right && (nums[left] == nums[left+ 1])) {
                            left++;
                        }
                    //skip duplicates
                        while (left < right && (nums[right] == nums[right - 1])) {
                            right--;
                        }
                        left++;
                        right--;
                    }
                    else{
                        left++;
                    }
                }
            }
        }
        return ans;
    }
};