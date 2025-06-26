/*
907. Sum of Subarray Minimums

https://leetcode.com/problems/sum-of-subarray-minimums/

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.


Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:
Input: arr = [11,81,94,43,3]
Output: 444
*/

#define MOD 1000000007

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
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


        int sum = 0;
        for(int i=0; i<n; i++){
            int leftRangeUntillSmallerElement = i - pse[i];
            int rightRangeUntillSmallerElement = nse[i] - i;

            sum = (sum + (1LL * leftRangeUntillSmallerElement * rightRangeUntillSmallerElement % MOD) * arr[i] % MOD) % MOD;
        }

        return sum;

    }
};