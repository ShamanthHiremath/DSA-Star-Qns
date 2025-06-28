/*
373. Find K Pairs with Smallest Sums

https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.
Define a pair (u, v) which consists of one element from the first array and one element from the second array.
Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.


Example 1:
Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:
Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
*/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        // stores {sum, i num1, j num2}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;

        // adding all sums of 1st ind nums1 and all nums2
        for(int j=0; j<min(n, k); j++){
            pq.emplace(nums1[0] + nums2[j], 0, j);
        }

        vector<vector<int>>ans;
        // adding pairs into res, and also pushing other possible minium sum pairs 
        while(k-- and !pq.empty()){
            auto [sum, i, j] = pq.top();
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});

            // this is to ensure that the next possible pair, (next to nums1[0], and all nums2[j] is inserted)
            if(i+1 < m){
                pq.emplace(nums1[i+1] + nums2[j], i+1, j);
            }
        }

        return ans;
    }
};