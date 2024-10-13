/*
Find the length of the longest subarray in which the sum of elements is equal to ‘K’.
If there is no subarray whose sum is ‘K’ then you should return 0.

Example:
Input: ‘N’ = 5,  ‘K’ = 4, ‘NUMS’ = [ 1, 2, 1, 0, 1 ]
Output: 4
There are two subarrays with sum = 4, [1, 2, 1] and [2, 1, 0, 1]. Hence the length of the longest subarray with sum = 4 is 4.
*/

#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& A, int K){
    int i=0;
    int len = 0;
    
    int sum = 0;
    int N = A.size();
    
    unordered_map<int, int>mp;
    
    while(i<N){
        sum += A[i];
        
        if(sum == K){
            len = i+1;
        }
        
        if(mp.find(sum -K) != mp.end()){
            len = max(len, i - mp[sum-K]);
        }
        
        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
        i++;
    }
    
    return len;
}