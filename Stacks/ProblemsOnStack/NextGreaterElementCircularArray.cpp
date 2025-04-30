/*
503. Next Greater Element II

https://leetcode.com/problems/next-greater-element-ii/

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.


Example 1:
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.

Example 2:
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
 
*/

class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            stack<int>st;
            st.push(-1);
    
            int n = nums.size();
            vector<int>ans(n, -1);
    
            // consider circular array so 2*n
            for(int i=0; i<2*n; i++){
                int num = nums[i % n];
    
                //  incoming number is greater than the top index (prev max indexes) repeat untill the prev max index is greater than the incoming num
                while(st.top() != -1 && nums[st.top()] < num){
                    // assign that prev max index to new max index number
                    ans[st.top()] = num;
                    // pop that prev index
                    st.pop();
                }
                // push all incoming indexes
                if(i<n) st.push(i);
            }
    
            return ans;
        }
    };