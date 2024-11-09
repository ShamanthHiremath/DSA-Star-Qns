/*
Subset Sums

https://www.geeksforgeeks.org/problems/subset-sums2234/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=subset-sums

Given a list arr of n integers, return sums of all subsets in it. Output sums can be printed in any order.

Example 1:
Input: n = 2, arr[] = {2, 3}
Output: 0 2 3 5
Explanation: When no elements is taken then Sum = 0. When only 2 is taken then Sum = 2. When only 3 is taken then Sum = 3. When element 2 and 3 are taken then Sum = 2+3 = 5.

Example 2:
Input: n = 3, arr = {1, 2, 1}
Output: 0 1 1 2 2 3 3 4
*/

class Solution {
  public:
    void solve(int index, int sum, vector<int>&arr, vector<int>&ans){
        ans.push_back(sum);
        
        for(int i=index; i<arr.size(); i++){
            sum += arr[i];
            solve(i+1, sum, arr, ans);
            sum -= arr[i];
        }
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int>ans;
        solve(0, 0, arr, ans);
        return ans;
    }
};