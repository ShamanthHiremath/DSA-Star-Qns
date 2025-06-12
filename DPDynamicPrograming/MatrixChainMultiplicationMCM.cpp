/*
Matrix Chain Multiplication

https://www.naukri.com/code360/problems/matrix-chain-multiplication_975344?leftPanelTabValue=PROBLEM

Problem statement
Given a chain of matrices A1, A2, A3,.....An. Your task is to find out the minimum cost to multiply these matrices. The cost of matrix multiplication is defined as the number of scalar multiplications. A Chain of matrices A1, A2, A3,.....An is represented by a sequence of numbers in an array ‘arr’ where the dimension of 1st matrix is equal to arr[0] * arr[1] , 2nd matrix is arr[1] * arr[2], and so on.

For example:
For arr[ ] = { 10, 20, 30, 40}, matrix A1 = [10 * 20], A2 = [20 * 30], A3 = [30 * 40]

Scalar multiplication of matrix with dimension 10 * 20 is equal to 200.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
2
4
4 5 3 2
4
10 15 20 25
Sample Output 1:
70
8000
Sample Output Explanation 1:
In the first test case, there are three matrices of dimensions A = [4 5], B = [5 3] and C = [3 2]. The most efficient order of multiplication is A * ( B * C).
Cost of ( B * C ) = 5 * 3 * 2 = 30  and (B * C) = [5 2] and A * (B * C) = [ 4 5] * [5 2] = 4 * 5 * 2 = 40. So the overall cost is equal to 30 + 40 =70.

In the second test case, there are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.

If we multiply in order- A1*(A2*A3), then the number of multiplications required is 11250.

If we multiply in order- (A1*A2)*A3, then the number of multiplications required is 8000.

Thus a minimum number of multiplications required is 8000. 
Sample Input 2:
1
4
1 4 3 2
Sample Output 2:
18
Explanation of Sample Output 2:
In the first test case, there are three matrices of dimensions A = [1 4], B = [4 3] and C = [3 2]. The most efficient order of multiplication is (A *  B) * C .
*/



#include <bits/stdc++.h> 

int solve(int i, int j, vector<int> &arr, vector<vector<int>>&dp){
    // this indicates there is just one MATRIX, so multiplication operations would be 0
    if(i == j){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int mini = 1e9;

    for(int k=i; k<j; k++){
        // steps needed for multiplying a segment to the left of k
        // and the segement  (k)
        // and the right of k
        // would be (arr[i-1] * arr[k] * arr[j])
        // mutliplied by left and right segemnts

        // (arr[i-1] * arr[k] * arr[j]) is because, the LEFT SIDE MATRICES upon MULTIPLICATION would have arr[i-1] as the no of rows of first Matrix, which upon mutliplication by the other matrices in the left is retained
        // similarly the arr[j] which rep the no of columns of the last RIGHT SIDE MATRICES, is retained
        // so the no of operations for multiplying any 2 matrices (A (m1 * n1), B (m2*n2*)), n1==m2
        // is m1*n1*n2 or m1*m2*n2, since n1==m2
        int steps_needed = (arr[i-1] * arr[k] * arr[j]) + solve(i, k, arr, dp) + solve(k+1, j, arr, dp);
        mini = min(steps_needed, mini);
        
    }


    return dp[i][j] = mini;

}

int solveTab(vector<int> &arr, int N){
    // base case has been covered in dp initialization 
    vector<vector<int>>dp(N+1, vector<int>(N+1, 0));

    // now reverse looping
    for(int i=N-1; i>=1; i--){
        // here it is j=i+1, since we are considering sub problems
        for(int j=i+1; j<=N-1; j++){
            int mini = 1e9; // Reset for each (i, j)

            for(int k=i; k<j; k++){
        
                int steps_needed = (arr[i-1] * arr[k] * arr[j]) + dp[i][k] + dp[k+1][j];
                mini = min(steps_needed, mini);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][N-1];
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>>dp(arr.size()+1, vector<int>(arr.size()+1, -1));

    // u go from 1 to n-1, since u check in that range since index 0, index 1 rep m*n for MAT 1
    // return solve(1, N-1, arr, dp);
    return solveTab(arr, N);
}