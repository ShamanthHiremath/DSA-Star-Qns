/*
Given an array of integers nums and a positive integer k, check whether it is possible to divide this array into sets of k consecutive numbers.

Return true if it is possible. Otherwise, return false.
*/

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0){
            return false;
        }
        
        // to store int and freq
        map<int, int> mp;
        for(auto i : nums){
            mp[i]++;
        }

        for(auto it : mp){
            int num = it.first;
            int freq = it.second;
            if(freq == 0){
                continue;
            }
            for(int i=num; i<k+num; i++){
                if(mp[i] < freq){
                    return false;
                }
                mp[i] -= freq;
            }
        }
        return true;
    }
};