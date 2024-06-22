/*Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays.*/
/*
Approach
Initialize Variables:

n: Length of the input array nums.
cnt: An array to keep track of the count of prefix sums (number of odd numbers encountered).
cnt[0]: Set to 1 initially, since a prefix sum of 0 (no odd numbers encountered) occurs once by default.
ans: Variable to store the final result (number of nice subarrays).
t: Variable to store the current count of odd numbers while iterating through the array.
Iterate Through the Array:

For each element v in nums, update the count of odd numbers (t) encountered so far. This is done by checking if v is odd using v & 1.
Check if there exists a prefix sum t - k (i.e., a previous state where there were t - k odd numbers). If so, add the count of such prefix sums to ans.
Increment the count of the current prefix sum (t) in the cnt array.
Return the Result:

After iterating through the entire array, ans will contain the number of nice subarrays.
*/

/*
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        vector<int>count(n+1, 0);
        count[0] = 1;
        int oddcnt = 0;

        for(int num : nums){
            // if(num % 2 == 1){
                // oddcnt++;
            // }
            oddcnt += num & 1;
            if(oddcnt - k>=0){
                ans += count[oddcnt-k];
            }
            count[oddcnt]++;
        }
        return ans;
    }
};