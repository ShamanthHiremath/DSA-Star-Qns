/*
354. Russian Doll Envelopes

You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
*/

class Solution {
public:
    int solveDP(int n, vector<vector<int>>& arr, int curr, int prev,
                vector<vector<int>>& dp) {
        if (curr >= n) {
            return 0;
        }

        if (dp[curr][prev + 1] != -1) {
            return dp[curr][prev + 1];
        }

        int incl = 0;
        if (prev == -1 || (arr[curr][0] > arr[prev][0] && arr[curr][1] > arr[prev][1])) {
            incl = 1 + solveDP(n, arr, curr + 1, curr, dp);
        }
        int excl = 0 + solveDP(n, arr, curr + 1, prev, dp);

        return dp[curr][prev + 1] = max(incl, excl);
    }

    public:
    // Custom comparator to sort envelopes
    static bool compare(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1]; // Sort heights in descending order if widths are the same
        }
        return a[0] < b[0]; // Otherwise, sort widths in ascending order
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // sort(envelopes.begin(), envelopes.end());
        // vector<vector<int>>dp(envelopes.size(), vector<int>(envelopes.size()+1, -1));
        // return solveDP(envelopes.size(), envelopes, 0, -1, dp);
        if (envelopes.empty()) return 0;

        // Sort envelopes
        sort(envelopes.begin(), envelopes.end(), compare);

        // Extract the heights from the sorted envelopes
        vector<int> heights;
        for (const auto& envelope : envelopes) {
            heights.push_back(envelope[1]);
        }

        // Find the length of LIS in heights
        return lengthOfLIS(heights);
    }

private:
    int lengthOfLIS(const vector<int>& nums) {
        vector<int> lis;

        for (int num : nums) {
            auto it = lower_bound(lis.begin(), lis.end(), num);
            if (it == lis.end()) {
                lis.push_back(num);
            } else {
                *it = num;
            }
        }

        return lis.size();
    }
};