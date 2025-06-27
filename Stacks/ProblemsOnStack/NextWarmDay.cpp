/*
739. Daily Temperatures

https://leetcode.com/problems/daily-temperatures/

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.


Example 1:
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Example 3:
Input: temperatures = [30,60,90]
Output: [1,1,0]
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<int>st;
        vector<int>nge(n, -1);
        st.push(-1);
        for(int i=n-1; i>=0; i--){
            while(st.top() != -1 and temp[st.top()] <= temp[i]){
                st.pop();
            }
            nge[i] = st.top();
            // extra if else step to cal DAYs for this problem // NOT in NGE
            if(nge[i] == -1){
                nge[i] = 0;
            }
            else{
                nge[i] -= i;
            }
            st.push(i);
        }

        return nge;

        return nge;

    }
};