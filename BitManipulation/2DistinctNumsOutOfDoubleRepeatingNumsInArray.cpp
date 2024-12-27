/*
Two numbers with odd occurrences

https://www.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1

Given an unsorted array, Arr[] of size N and that contains even number of occurrences for all numbers except two numbers. Find the two numbers in decreasing order which has odd occurrences.

Example 1:
Input:
N = 8
Arr = {4, 2, 4, 5, 2, 3, 3, 1}
Output: {5, 1} 
Explanation: 5 and 1 have odd occurrences.
*/

class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        
        long long xorr = 0;
        
        for(long long i=0; i<N; i++){
            xorr = xorr ^ Arr[i];
        }
        
        // Setting the rightmost set bit of the XORR of those two distinct numbers (rest get cancelled out)
        xorr = (xorr & (xorr-1)) ^ xorr;
        // xorr = xorr & ((~xorr)+1)
        
        long long bucket1 = 0, bucket2 = 0;
        
        for(long long i=0; i<N; i++){
            // the distinct number with 1 set bit is pushed to bucket 1, while the duplicates get eliminated
            if(xorr & Arr[i]){
                bucket1 ^= Arr[i];
            }
            else{
                bucket2 ^= Arr[i];
            }
        }
        
        if(bucket1>bucket2){
            return {bucket1, bucket2};
        }
        return {bucket2, bucket1};
    }
};