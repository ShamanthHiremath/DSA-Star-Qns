/*
240. Search a 2D Matrix II

https://leetcode.com/problems/search-a-2d-matrix-ii/description/

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 
Example 1:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

Example 2:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
*/

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& arr, int target) {
            int rows=arr.size();
            int col=arr[0].size();
            int r=0;
            int c=col-1;
            while(r<rows && c>=0){
                if(arr[r][c]==target){
                    return true;
                }
                if(arr[r][c]>target){
                    c--;
                }
                else{
                    r++;
                }
            }
            return false;
            
        }
    };