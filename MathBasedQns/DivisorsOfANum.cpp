/*
All divisors of a Number

https://www.geeksforgeeks.org/problems/all-divisors-of-a-number/1

Given an integer N, print all the divisors of N in the ascending order.

Example 1:

Input : 20
Output: 1 2 4 5 10 20
Explanation: 20 is completely 
divisible by 1, 2, 4, 5, 10 and 20.

Example 2:

Input: 21191
Output: 1 21191
Explanation: As 21191 is a prime number,
it has only 2 factors(1 and the number itself).
*/
class Solution {
  public:
    void print_divisors(int n) {
        /*
        n= 16
        sq = 4
        deq 1 2 4 8 16
        value of sq over iteration which go inside the if condn.
        4
        2
        1
        0
        */
        
        if(n == 1){
            cout<<1;
            return;
        }
        
        deque<int>dq;
        
        int sq = sqrt(n);
        
        while(sq>0){
            // if the sqrt exits, if its an integer (meaning its not float)
            if(n%sq == 0){
                // then add that to the front
                dq.push_front(sq);
                
                // this is to avoid adding the same SQ twice, because 
                // suppose n = 4,m sq=2, sq == n/sq, so u add it again.
                if(sq != n/sq){
                    // follows the property if a = x/b, then and b divides x, then a* b = x
                    dq.push_back(n/sq);
                }
            }
            sq--;
        }
        
        for(int &x: dq){
            cout<<x<<" ";
        }
        
    }
};