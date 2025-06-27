/*
202. Happy Number

https://leetcode.com/problems/happy-number/description/

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.


Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false
*/


// SOLUTION 
// https://leetcode.com/problems/happy-number/solutions/3767573/easy-java-solution-two-pointers-floyd-s-tortoise-and-hare-detailed-explanation

class Solution {
public:
    int gensumofsq(int n){
        int sumofsq=0;
        while(n!=0){
            int digit=n%10;
            n/=10;
            sumofsq=sumofsq + digit*digit;
        }
        return sumofsq;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do{
            slow = gensumofsq(slow);
            fast = gensumofsq(gensumofsq(fast));
        }while(slow != fast);

        return slow == 1;
    }
};