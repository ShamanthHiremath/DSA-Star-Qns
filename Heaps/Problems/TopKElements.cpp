/*
347. Top K Frequent Elements

https://leetcode.com/problems/top-k-frequent-elements/description/

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        for(int num : nums) {
            mp[num]++;
        }
        
        priority_queue<pair<int, int>> pq;
        for(auto it : mp) {
            pq.push({it.second, it.first});
        }
        
        vector<int> ans;
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};