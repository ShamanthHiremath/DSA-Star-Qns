/*
The fence has 'N' posts, and Ninja has 'K' colors. Ninja wants to paint the fence so that not more than two adjacent posts have the same color.
*/

#include <vector>
using namespace std;

#define MOD 1000000007

int solveDP(int n, int k, vector<int>& dp) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return k;
    }
    if (n == 2) {
        return (k % MOD + ((k % MOD) * (k - 1) % MOD)) % MOD;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    long long int ans = ((k - 1LL) * (solveDP(n - 2, k, dp) % MOD + solveDP(n - 1, k, dp) % MOD)) % MOD;
    return dp[n] = (ans + MOD) % MOD; // Ensure the result is non-negative
}

int numberOfWays(int n, int k) {
    vector<int> dp(n + 1, -1);
    return solveDP(n, k, dp);
}
