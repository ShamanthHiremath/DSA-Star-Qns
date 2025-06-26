/*
Minimum number of Coins

https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } and a target value N.
Find the minimum number of coins and/or notes needed to make the change for Rs N. You must return the list containing the value of coins required. 

Example 1:
Input: N = 43
Output: 20 20 2 1
Explaination: 
Minimum number of coins and notes needed 
to make 43. 

Example 2:
Input: N = 1000
Output: 500 500
Explaination: minimum possible notes
is 2 notes of 500.
*/

class Solution {
  public:
    vector<int> minPartition(int N) {
        // code here
        vector<int>ans;
        vector<int>coin = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        while(N > 0){
            for(int i=coin.size()-1; i>=0; i--){
                if(coin[i] > N){
                    continue;
                }
                
                int coinsNeeded = N / coin[i];
                for(int j=0; j<coinsNeeded; j++){
                    ans.push_back(coin[i]);
                }
                N %= coin[i];
            }
        }
        return ans;
    }
};