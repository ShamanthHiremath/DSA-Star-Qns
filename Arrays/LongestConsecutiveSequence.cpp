/*
128. Longest Consecutive Sequence

https://leetcode.com/problems/longest-consecutive-sequence/description/

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int ans = 0;

        for(int num:nums){
            st.insert(num);
        }

        for(int num: st){
            if(st.find(num-1) == st.end()){
                int seqlen = 1;
                int x = num;
                while(st.find(x+1) != st.end()){
                    x++;
                    seqlen++;
                }
                ans = max(ans, seqlen);
            }
        }

        return ans;
    }
};

// OOOOORRRRRR

class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        if(!a.size()){
            return 0;
        }
        // Write your code here.
        sort(a.begin(), a.end());
        int maxi = 1;
        int curr = 1;
        int i=0;
        while(i<a.size()-1){
        if (i < a.size() - 1 && (a[i] + 1 == a[i + 1] || a[i] == a[i+1])) {
            curr = 1;
            while(1){
                if(i<a.size()-1 && a[i] == a[i+1] ){
                    i++;
                }
                else if(i<a.size()-1 && a[i]+1 == a[i+1]){
                    curr++;
                    i++;
                }
                else{
                    break;
                }
            }
            maxi = max(maxi, curr);
        }
        else{
            i++;
        }
            
        }
        return maxi;
    }
};