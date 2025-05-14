/*
1901. Find a Peak Element II

https://leetcode.com/problems/find-a-peak-element-ii/

https://leetcode.com/problems/find-a-peak-element-ii/solutions/1276556/java-python-c-clear-explanation-with-images-m-log-n-very-short-code/

A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.


Logic:
For given matrix[M][N], create a new 1D array maxPlaneOfCol[N] which stores the largest number in each column.

image

For the above matrix, maxPlaneOfCol = {4, 9, 6, 3, 7, 5}
Let maxPlaneOfCol[i] represent a height of the plane at index i
image

Now we have reduced the 2D problem to a 1D problem. Using the same logic as in Solution-Find-Peak-Element, we can find the column that has the peak plane. Remember, the elements in maxPlaneOfCol represent the largest number of each column. If we find a peak plane at index 'p', then it means that there is an element in column# p which is bigger than all the elments in column# p-1 and column# p+1. Once we have the peak column p, we can easily find the row# of the peak element in the column# p. Now you have both row# and col# of a peak element in 2D array. Thats it !!

BUT!! BUT!! BUT!!

To populate maxPlaneOfCol[N], we need to traverse all the columns in the 2D array, which basically means that we have to read all the elements in 2D array. So, when you are reading the entire 2D array, why not just return the coordinates of the largest number in the 2D array ?!! The largest element is gauranteed to be a peak element, isn't it !!??

HOLD ON 🤔🤔🤔

Do we really need to find the max in each and every column? Will it not be sufficent to just find the max of the midColumn ? If we find the max of only the midColumn, we will calculate max of only log(N) columns in our entire algorithm.
Hence the Time Complexity is M*log(N). Below is the prettiest code I could come up with.




Example 1:
Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.

Example 2:
Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
*/
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int startCol = 0, endCol = mat[0].size()-1;
        while(startCol <= endCol){
            int maxRow = 0;
            // the mid column is choosen to detect a peak element in that column
            int midCol = startCol + (endCol - startCol)/2;

            // in a midCol find the maximum element (peak)
            for(int row=0; row<mat.size(); row++){
                if(mat[row][midCol] >= mat[maxRow][midCol]){
                    maxRow = row;
                }
            }

            // check if the element on the right and left is bigger or not
            bool leftBig = (midCol-1 >= startCol) && (mat[maxRow][midCol-1] > mat[maxRow][midCol]);

            bool rightBig = (midCol+1 <= endCol) && (mat[maxRow][midCol+1] > mat[maxRow][midCol]);

            
            // if both are false, ie the peak elemnent is found
            if(!leftBig && !rightBig){
                return vector<int>{maxRow, midCol};
            }
            if(rightBig){
                startCol = midCol + 1;
            }
            else{
                endCol = midCol - 1;
            }
        }

        return vector<int>{-1, -1};
    }
};