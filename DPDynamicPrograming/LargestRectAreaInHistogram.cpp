/*
84. Largest Rectangle in Histogram

https://leetcode.com/problems/largest-rectangle-in-histogram/

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4
*/

class Solution {
public:
    vector<int>prevsmallerindex(vector<int> heights, int n){
        stack<int>s;
        vector<int>ans(n);
        s.push(-1);
        for(int i=0; i<n; i++){
            while(s.top()!=-1 && heights[s.top()]>=heights[i]){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;

    }
    vector<int>nextsmallerindex(vector<int> heights, int n){
        stack<int>s;
        vector<int>ans(n);
        s.push(-1);
        for(int i=n-1; i>=0; i--){
            //int store=heights[i];
            while(s.top()!=-1 && heights[s.top()]>=heights[i]){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next(n);
        next=nextsmallerindex(heights,n);
        vector<int>prev(n);
        prev=prevsmallerindex(heights,n);
        int area=INT_MIN;
        for(int i=0; i<n; i++){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            // if(prev[i]==-1){
            //     prev[i]=1;
            // }
            int b=next[i]-prev[i]-1;
            // area=l*b;
            area=max(area, l*b);
        }
        return area;

    }
};