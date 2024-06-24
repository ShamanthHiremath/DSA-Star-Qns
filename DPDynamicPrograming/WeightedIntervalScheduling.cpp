/*
1235. Maximum Profit in Job Scheduling

We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].
You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.
If you choose a job that ends at time X you will be able to start another job that starts at time X.

Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.
*/

class Solution {
public:
    // Helper function to find the latest job that doesn't overlap using binary search
    int find_latest_non_overlapping(vector<int>& startTime, vector<int>& endTime, int index) {
        int low = 0, high = index - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (endTime[mid] <= startTime[index]) {
                if (endTime[mid + 1] <= startTime[index]) {
                    low = mid + 1;
                } else {
                    return mid;
                }
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    int solveDP(vector<int>& startTime, vector<int>& endTime, vector<int>& profit, vector<int>& dp, int index) {
        // base case
        if (index == -1) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        
        // recursion either include or exclude
        int incl = profit[index];
        int j = find_latest_non_overlapping(startTime, endTime, index);
        if (j != -1) {
            incl += solveDP(startTime, endTime, profit, dp, j);
        }

        int excl = solveDP(startTime, endTime, profit, dp, index - 1);
        return dp[index] = max(incl, excl);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = endTime.size();
        vector<int> dp(n, -1);

        // Create a vector of jobs and sort by end time
        vector<tuple<int, int, int>> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back(make_tuple(endTime[i], startTime[i], profit[i]));
        }
        sort(jobs.begin(), jobs.end());

        // Extract the sorted times and profits
        for (int i = 0; i < n; ++i) {
            endTime[i] = get<0>(jobs[i]);
            startTime[i] = get<1>(jobs[i]);
            profit[i] = get<2>(jobs[i]);
        }

        // Calculate maximum profit using the DP approach
        return solveDP(startTime, endTime, profit, dp, n - 1);
    }
};
