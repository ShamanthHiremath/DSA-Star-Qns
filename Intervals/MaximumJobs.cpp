/*
N meetings in one room

https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 
Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Examples :

Input: start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)
Input: start[] = [10, 12, 20], end[] = [20, 25, 30]
Output: 1
Explanation: Only one meetings can be held with given start and end timings.
*/

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int> start, vector<int> end) {
        // Your code here
        int n = start.size();
        vector<pair<int, int>> endstart;
        
        for(int i=0; i<n; i++){
            endstart.push_back({end[i], start[i]});
        }
        
        sort(endstart.begin(), endstart.end());
        
        int count = 1;
        int prev_endtime = endstart[0].first;
        for(int i=1; i<n; i++){
            int next_starttime = endstart[i].second;
            if(next_starttime > prev_endtime){
                count++;
                prev_endtime = endstart[i].first;
            }
        }
        
        return count;
    }
};