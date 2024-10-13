/*
1691. Maximum Height by Stacking Cuboids 

https://leetcode.com/problems/maximum-height-by-stacking-cuboids/

******************************************************************************************************
SORT THE CUBOIDS ON THE BASIS OF WIDTH/LENGTH AND CHECK USING DP IF THE CUBOID CAN BE PLACED ON TOP OF ANOTHER CUBOID
******************************************************************************************************

Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.

You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return the maximum height of the stacked cuboids.

Example 1:
Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
Output: 190
Explanation:
Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
Cuboid 0 is placed next with the 45x20 side facing down with height 50.
Cuboid 2 is placed next with the 23x12 side facing down with height 45.
The total height is 95 + 50 + 45 = 190.
Example 2:

Input: cuboids = [[38,25,45],[76,35,3]]
Output: 76
Explanation:
You can't place any of the cuboids on the other.
We choose cuboid 1 and rotate it so that the 35x3 side is facing down and its height is 76.
Example 3:

Input: cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]
Output: 102
Explanation:
After rearranging the cuboids, you can see that all cuboids have the same dimension.
You can place the 11x7 side down on all cuboids so their heights are 17.
The maximum height of stacked cuboids is 6 * 17 = 102.
*/

class Solution {
private:
    bool check(vector<int>big, vector<int>small){
        if(small[0] <= big[0] && small[1] <= big[1] && small[2] <= big[2]){
            return true;
        }
        else{
            return false;
        }
    }
public:
    int solve(int n, vector<vector<int>>& cuboids){
        vector<int>currow(n+1, 0);
        vector<int>prevrow(n+1, 0);

        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int include = 0;
                // include the height of  the cuboid if it fits
                if(prev == -1 || check(cuboids[curr], cuboids[prev])){
                    include = cuboids[curr][2] + prevrow[curr + 1];
                }
                int exclude = 0 + prevrow[prev + 1];

                currow[prev + 1] =  max(include, exclude);
            }
            prevrow = currow;
        }

        return prevrow[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // sorting on the basis of the height being the highest
        for(auto &a: cuboids){
            sort(a.begin(), a.end());
        }
        // sort on the basis of width/length
        sort(cuboids.begin(), cuboids.end());

        return solve(cuboids.size(), cuboids);

    }
};