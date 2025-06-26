/*
2104. Sum of Subarray Ranges

https://leetcode.com/problems/sum-of-subarray-ranges/description/

You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.

Example 2:
Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.

Example 3:
Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.
*/
class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr) {
        // figure out Next smaller element
        // figure out Prev Smaller element
        // the index range between the NSE and PSE would give the subarray which has the current element as the minimummost
        int n = arr.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i] = st.top();
            }
            else{
                nse[i] = n;
            }

            st.push(i);
        }
        
        
        
        vector<int>pse(n);
        stack<int>st2;

        for(int i=0; i<n; i++){
            while(!st2.empty() and arr[st2.top()] > arr[i]){
                st2.pop();
            }
            if(!st2.empty()){
                pse[i] = st2.top();
            }
            else{
                pse[i] = -1;
            }

            st2.push(i);
        }


        long long sum = 0;
        for(int i=0; i<n; i++){
            int leftRangeUntillSmallerElement = i - pse[i];
            int rightRangeUntillSmallerElement = nse[i] - i;

            sum = (sum + (1LL * leftRangeUntillSmallerElement * rightRangeUntillSmallerElement ) * arr[i] ) ;
        }

        return sum;

    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        // figure out Next greater element
        // figure out Prev greater element
        // the index range between the NSE and PSE would give the subarray which has the current element as the maximummost
        int n = arr.size();
        vector<int>nge(n);
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and arr[st.top()] <= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nge[i] = st.top();
            }
            else{
                nge[i] = n;
            }

            st.push(i);
        }
        
        
        
        vector<int>pge(n);
        stack<int>st2;

        for(int i=0; i<n; i++){
            while(!st2.empty() and arr[st2.top()] < arr[i]){
                st2.pop();
            }
            if(!st2.empty()){
                pge[i] = st2.top();
            }
            else{
                pge[i] = -1;
            }

            st2.push(i);
        }


        long long sum = 0;
        for(int i=0; i<n; i++){
            int leftRangeUntillSmallerElement = i - pge[i];
            int rightRangeUntillSmallerElement = nge[i] - i;

            sum = (sum + (1LL * leftRangeUntillSmallerElement * rightRangeUntillSmallerElement ) * arr[i] ) ;
        }

        return sum;

    }


    long long subArrayRanges(vector<int>& nums) {
        // this is because the difference between one subarray max and one sub array min would actually mean the difference between Sum of all subarraymaxes and Sum of all subbarray mins
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);

    }
};