#include <bits/stdc++.h> 
int countDistinctWays(int nStairs) {
    if(nStairs==1|| nStairs==2) return nStairs;
    //if(nStairs==3)return 3;
    if(nStairs<0)return 0;
    if(nStairs==0)return 1;
    long long int ans=countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2);

    return ans;
}