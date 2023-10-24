class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //vector<int> store(nums.size(),0);
        unordered_map<int,int> store;
        for(int i=0; i<nums.size();i++){
            if(store.count(nums[i])){
                if(abs(i-store[nums[i]])<=k){
                    return true;
                }
            }
            store[nums[i]]=i;
        }
        return false;    
    }
};