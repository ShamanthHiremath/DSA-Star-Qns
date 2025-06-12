/*
Longest Bitonic Sequence

https://www.naukri.com/code360/problems/longest-bitonic-sequence_1062688

Problem statement
A Bitonic Sequence is a sequence of numbers that is first strictly increasing and then strictly decreasing.



A strictly ascending order sequence is also considered bitonic, with the decreasing part as empty, and same for a strictly descending order sequence.



For example, the sequences [1, 3, 5, 3, 2], [1, 2, 3, 4] are bitonic, whereas the sequences [5, 4, 1, 4, 5] and [1, 2, 2, 3] are not.



You are given an array 'arr' consisting of 'n' positive integers.



Find the length of the longest bitonic subsequence of 'arr'.



Example :
Input: 'arr' = [1, 2, 1, 2, 1]

Output: 3

Explanation: The longest bitonic subsequence for this array will be [1, 2, 1]. Please note that [1, 2, 2, 1] is not a valid bitonic subsequence, because the consecutive 2's are neither strictly increasing, nor strictly decreasing.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
5 
1 2 1 2 1


Sample Output 1:
3

Explanation For Sample Input 1:
The longest bitonic subsequence for this array will be [1, 2, 1]. Please note that [1, 2, 2, 1] is not a valid bitonic subsequence, because the consecutive 2's are neither strictly increasing, nor strictly decreasing.


Sample Input 2 :
5
1 2 1 3 4


Sample Output 2 :
4

Explanation For Sample Input 2:
The longest bitonic sequence for this array will be [1, 2, 3, 4].
*/


int longestBitonicSubsequence(vector<int>& nums, int n)
{
	// Write your code here.

	// LIS CODE IS APPLIED TWICE
	// ONCE FOR START TO END, TO IDENTIFY, INCREASING SUBSEQUENCE
	// AGAIN FOR END TO START, TO IDENTIFY, INCREASING SUBSEQUENCE FROM THE BACK WHICH WILL GIVE US DECREASING SUBS LOGICALLY

	// Code for LIS from 0 to n
	// stores the length of LIS untill that index
	vector<int>dp(n, 1);


	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if(nums[j] < nums[i] and dp[j] + 1 > dp[i]){
				// if the current number is greater than the previous number
				// and the LIS length at j + 1 is greater than the current LIS length at i
				dp[i] =  dp[j] + 1;
			}
		}
	}


	// code for LIS from n to 0
	vector<int>dp2(n, 1);


	for(int i=n-1; i>=0; i--){
		for(int j=n-1; j>=i; j--){
			if(nums[j] < nums[i] and dp2[j] + 1 > dp2[i]){
				// if the current number is greater than the previous number
				// and the LIS length at j + 1 is greater than the current LIS length at i
				dp2[i] =  dp2[j] + 1;
			}
		}
	}


	// LARGEST LENGTH BI-TONIC SUBSEQUENCE
	int maxiLen = 1;
	for(int i=0; i<n; i++){
		maxiLen = max(maxiLen, dp[i] + dp2[i] - 1);
	}

	return maxiLen;



}

