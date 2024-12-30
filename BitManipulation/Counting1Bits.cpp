/*
191. Number of 1 Bits

https://leetcode.com/problems/number-of-1-bits/description/

Given a positive integer n, write a function that returns the number of 
set bits in its binary representation (also known as the Hamming weight).

Example 1:
Input: n = 11
Output: 3
Explanation:
The input binary string 1011 has a total of three set bits.
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        short int count=0;
        if(n==0){
            return 0;
        }
        while(n!=0){
            if(n&1==1){ // count+=n%2;
                count++;
            }
            n=n>>1; // n=n/2;
        }
        return count;
    }
};