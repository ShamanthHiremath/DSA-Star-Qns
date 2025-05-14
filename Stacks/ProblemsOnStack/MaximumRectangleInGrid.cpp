/*
85. Maximal Rectangle

https://leetcode.com/problems/maximal-rectangle/

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:
Input: matrix = [["0"]]
Output: 0

Example 3:
Input: matrix = [["1"]]
Output: 1
 
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

    int maximalRectangle(vector<vector<char>>& matrix) {

        vector<int>histogram(matrix[0].size(), 0);
        int maxi = 0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                // add one block of height to that column
                if(matrix[i][j] == '1'){
                    histogram[j] ++;
                }
                // make it 0
                else{
                    histogram[j] = 0;
                }
            }
            maxi = max(maxi, largestRectangleArea(histogram));
        }
        return maxi;
    }
};