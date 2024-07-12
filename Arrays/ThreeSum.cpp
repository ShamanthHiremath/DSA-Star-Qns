/*
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        //set<vector<int>> set;
        vector<vector<int>> ans;
        int sum;
        int i=0;
        while(i<nums.size()-1){
            if(nums[i]>0){
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                i++;
                continue; 
                // Skip duplicate elements
            }
            int j=i+1, k=nums.size()-1;
            //sum=nums[i];
            while(j<k){
                sum=nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }
                else if(sum==0){
                    ans.push_back({nums[i], nums[j],nums[k]});
                    //set.insert({nums[i], nums[j],nums[k]});
                    //skips the necessity for this 
                    //skip duplicates
                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    //skip duplicates
                    while (j < k && nums[k] == nums[k - 1]) {
                        k--;
                    }
                    j++;
                    k--;
                }
                else{
                    j++;
                }
            }
            i++;
        }
        //if a set is used iterate and add
        // for(auto it : set){
        //     ans.push_back(it);
        // }
        return ans;       
    }
};