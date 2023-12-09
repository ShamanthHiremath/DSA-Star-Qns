#include <bits/stdc++.h> 
//exceeds time limits
int countDistinctWays(int nStairs) {
    if(nStairs==1|| nStairs==2) return nStairs;
    //if(nStairs==3)return 3;
    if(nStairs<0)return 0;
    if(nStairs==0)return 1;
    long long int ans=countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2);

    return ans;
}

//doesnot exceed time limit by searching in the map
class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int, int> memo;
        return climbStairsMemo(n, memo);
    }

private:
    int climbStairsMemo(int n, unordered_map<int, int>& memo) {
        if (n == 0) return 0;
        if (n == 1|| n==2) return n;

        if (memo.find(n) != memo.end()) {
            return memo[n];
        }

        int ways = climbStairsMemo(n - 1, memo) + climbStairsMemo(n - 2, memo);
        memo[n] = ways;

        return ways;
    }
};
//normal method
class Solution {
public:
    int climbStairs(int n) {
 
        int prev1 = 1, prev2 = 1, current = 1;
        for(int i = 2; i <= n; i ++) {
            current = prev1 + prev2;
            prev1 = prev2;
            prev2 = current;
        }
        return current;
        
    }
};