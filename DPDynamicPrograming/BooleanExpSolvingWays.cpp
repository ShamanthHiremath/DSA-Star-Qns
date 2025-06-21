/*
Boolean Evaluation

https://www.naukri.com/code360/problems/problem-name-boolean-evaluation_1214650?leftPanelTabValue=PROBLEM

Problem statement

You are given an expression 'exp' in the form of a string where operands will be : (TRUE or FALSE), and operators will be : (AND, OR or XOR).

Now you have to find the number of ways we can parenthesize the expression such that it will evaluate to TRUE.

As the answer can be very large, return the output modulo 1000000007.

Note :

‘T’ will represent the operand TRUE.
‘F’ will represent the operand FALSE.
‘|’ will represent the operator OR.
‘&’ will represent the operator AND.
‘^’ will represent the operator XOR.
Example :

Input: 'exp’ = "T|T & F".

Output: 1

Explanation:
There are total 2  ways to parenthesize this expression:
    (i) (T | T) & (F) = F
    (ii) (T) | (T & F) = T
Out of 2 ways, one will result in True, so we will return 1.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
T^T^F    
Sample Output 1 :
0
Explanation For Sample Input 1:
There are total 2  ways to parenthesize this expression:
(i) (T^T)^(F) = F
(ii) (T)^(T^F) = F
Both ways will result in False, so we will return 0.
Sample Input 2 :
F|T^F
Sample Output 2 :
2
Explanation For Sample Input 2:
For the first test case:
There are total 2  ways to parenthesize this expression:
(i) (F|T)^(F) = T
(ii) (F)|(T^F) = T
Both ways will result in True, so we will return 2.
*/

long long mod = 1000000007;

long long solveDP(int i, int j, bool isTrue, string &exp, vector<vector<vector<int>>>&dp){
    // out of boundary, 0 ways
    if(i>j){
        return 0;
    }
    if(i==j){
        if(isTrue){
            return exp[i]=='T';
        }
        else{
            return exp[i]=='F';
        }
    }

    if(dp[i][j][isTrue] != -1){
        return dp[i][j][isTrue];
    }

    long long lT, rT, lF, rF;

    long long ways = 0;

    for(int ind=i+1; ind<j; ind+=2){
        lT = solveDP(i, ind-1, true, exp, dp);
        lF = solveDP(i, ind-1, false, exp, dp);
        rT = solveDP(ind+1, j, true, exp, dp);
        rF = solveDP(ind+1, j, false, exp, dp);
        if(exp[ind] == '&'){
            if(isTrue){
                ways = (ways + (lT * rT) % mod) % mod;
            }
            else{
                ways = (ways + (lT*rF)%mod + (lF*rT)%mod + (lF*rF)%mod) % mod;
            }
        }
        else if(exp[ind] == '|'){
            if(isTrue){
                ways = (ways + (lT*rF)%mod + (lF*rT)%mod + (lT*rT)%mod) % mod;
            }
            else{
                ways = (ways + (lF*rF)%mod) % mod;
            }
        }
        else if(exp[ind] == '^'){
            if(isTrue){
                ways = (ways + (rT*lF)%mod + (rF*lT)%mod) % mod;
            }
            else{
                ways = (ways + (rF*lF)%mod + (rT*lT)%mod) % mod;
            }
        }

    }
    
    return dp[i][j][isTrue] = ways;
}


int evaluateExp(string & exp) {
    // Write your code here.

    int n = exp.size();
    vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));

    return solveDP(0, n-1, true, exp, dp);
}

