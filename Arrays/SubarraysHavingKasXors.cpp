/*
Count Subarrays with given XOR

https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1

Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.

Examples: 

Input: arr[] = [4, 2, 2, 6, 4], k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 6 are [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6]. Hence, the answer is 4.

Input: arr[] = [5, 6, 7, 8, 9], k = 5
Output: 2
Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]. Hence, the answer is 2.

Input: arr[] = [1, 1, 1, 1], k = 0
Output: 4
Explanation: The subarrays are [1, 1], [1, 1], [1, 1] and [1, 1, 1, 1].
*/

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        
        int n = arr.size();
        // mp to keep a count of the no of xorr subarrays that would give K (xorrx = xorr^k,  )
        unordered_map<int, int>mp;
        mp[0] = 1;
        int count = 0;
        int xorr = 0;
        
        int i=0;
        while(i<n){
            xorr ^= arr[i];
            
            // x ^ k = xorr
            // xor k on B.S
            // x = xorr ^ k
            // x represents the xorr of left part before the subarry which has k, which is to be removed from xorr in order to get k
            int x = xorr ^ k;
            
            // increase the count based on the no of occurences of that x in mp
            count += mp[x];
            
            // increase the count of xorr subarray occurences
            mp[xorr]++;

            i++;
        }
        
        return count;
        
    }
};