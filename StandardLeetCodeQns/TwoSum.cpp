// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //sort(nums.begin(), nums.end()-1);
        vector<int> ans;
        unordered_map<int, int> hashmapp;
        for(int i=0; i<nums.size(); i++){
            // say 1+2=3 complement is 1=3-2
            int complement=target-nums[i];
            //hashmapp.find(element) returns the iterator poinnting to the element in hashmap
            //or else  it returns end()

            //if complement is found.... add it to ans vector and return 
            if(hashmapp.find(complement)!=hashmapp.end()){
                ans.push_back(hashmapp[complement]);
                ans.push_back(i);
                return ans;
            }
            //add value of num[i] as key and position as elemnt to the key
            hashmapp[nums[i]]=i;
        }
        return ans;
    }

};