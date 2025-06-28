/*
Maximum Sum Combination

https://www.geeksforgeeks.org/problems/maximum-sum-combination/1

Given two integer array A and B of size N each.
A sum combination is made by adding one element from array A and another element of array B.
Return the maximum K valid sum combinations from all the possible sum combinations.

Note : Output array must be sorted in non-increasing order.

Example 1:

Input:
N = 2
K = 2
A [ ] = {3, 2}
B [ ] = {1, 4}
Output: {7, 6}
Explanation: 
7 -> (A : 3) + (B : 4)
6 -> (A : 2) + (B : 4)

Example 2:

Input:
N = 4
K = 3
A [ ] = {1, 4, 2, 3}
B [ ] = {2, 5, 1, 6}
Output: {10, 9, 9}
Explanation: 
10 -> (A : 4) + (B : 6)
9 -> (A : 4) + (B : 5)
9 -> (A : 3) + (B : 6)
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxCombinations() which takes the interger N,integer K and two integer arrays A [ ] and B [ ] as parameters and returns the maximum K valid distinct sum combinations .
*/

class Solution {
  public:
    vector<int> maxCombinations(int N, int k, vector<int> &nums1, vector<int> &nums2) {
        // code here
        int m = nums1.size();
        int n = nums2.size();
        // stores {sum, i num1, j num2}
        priority_queue<tuple<int, int, int>>pq;
        
        // sorting arrays in descending order
        sort(nums1.begin(), nums1.end(), greater<int>());
        sort(nums2.begin(), nums2.end(), greater<int>());
        
        // adding all sums of 1st ind nums1 and all nums2
        for(int j=0; j<min(n, k); j++){
            pq.emplace(nums1[0] + nums2[j], 0, j);
        }

        vector<int>ans;
        // adding pairs into res, and also pushing other possible maximum sum pairs 
        while(k-- and !pq.empty()){
            auto top = pq.top();
            int sum = get<0>(top);
            int i = get<1>(top);
            int j = get<2>(top);

            pq.pop();
            ans.push_back(sum);

            // this is to ensure that the next possible pair, (next to nums1[0], and all nums2[j] is inserted)
            if(i+1 < m){
                pq.emplace(nums1[i+1] + nums2[j], i+1, j);
            }
        }
        
        return ans;
    }
};