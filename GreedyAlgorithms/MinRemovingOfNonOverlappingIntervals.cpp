/*
435. Non-overlapping Intervals

https://leetcode.com/problems/non-overlapping-intervals/

Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

 

Example 1:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Example 3:
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int removed = 0;

        sort(intervals.begin(), intervals.end());
        vector<int>prev = intervals[0];
        
        int i=1;
        while(i<intervals.size()){
            vector<int> curr = intervals[i];

            // OVERLAP CASES
            // ending time of previousinterval is > than starting time of current interval
            if(prev[1] > curr[0]){
                // CASE 1: CURR IS BIGGER THAN PREV
                if(prev[1] < curr[1]){
                    // keeping the previous as it is
                    // since the bigger curr can be removed, which might cover other intervals
                    removed++;
                }
                // CASE 2: PREV IS BIGGER THAN CURR
                else if(prev[1] > curr[1]){
                    // keeping the current as it is
                    // since the bigger prev can be removed, which might cover other intervals
                    prev = curr;
                    removed++;
                }
                else{
                    // cuz the bigger interval ie prev can be removed
                    prev = curr;
                    removed++;
                }
            }
            // CASE 3: NO OVERLAP
            else{
                prev = curr;
            }
            i++;
        }


        return removed;

    }
};