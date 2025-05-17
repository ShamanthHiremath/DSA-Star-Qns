/*
1707. Maximum XOR With an Element From Array

https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

Example 1:
Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
Output: [3,3,7]
Explanation:
1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.

Example 2:
Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
Output: [15,-1,5]
*/

/*

TLE

public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                maxi = max(maxi, nums[i]^nums[j]);
            }
        }
        return maxi;
    }
};
*/

// this data structure defines the NODE in a TRIE,
// the NODE has 2 links, which store presence of 1 and 0 (if links[0] is NULL, then not present and vis a vis)
class Node{
    Node* links[2];

public:
// checks for presence of 1 or 0 in the NODE
    bool containsKey(int bit){
        return (links[bit] != NULL);
    }

// gets the NODE with that LINK
    Node* getLink(int bit){
        return links[bit];
    }

// adds a NEW LINK to the non-exsting LINK
    void putLink(int bit, Node* node){
        links[bit] = node;
    }
};



// TRIE DATA STRUCTURE
class Trie{
    Node* root;
public:
// Stores ROOT as the entry point
    Trie(){
        root = new Node();
    }

// INSERTs the number (each bit of the number is extracted and added into the TRIE)
    void insert(int num){
        // first point of traversal
        Node* node = root;
        // 32 bits are extracted from NUM and added
        for(int i=31; i>=0; i--){
            // extracts i th bit from right to left;
            int bit = (num >> i) & 1;

            // if that bit has not been linked, or added, then u make a new link and add
            if(!node->containsKey(bit)){
                node->putLink(bit, new Node());
            }
            // move to the next LINK
            node = node->getLink(bit);
        }
    }

    // gets the maximum most XOR ans when XORed with TRIE nums and new NUM 
    int getMax(int num){
        Node* node = root;

        int maxNum = 0;

        for(int i=31; i>=0; i--){
            // ith bit from the right to left is extracted
            int bit = (num >> i) & 1;

            // If the complement of the current
            // bit exists in the Trie
            // this is done because when we xor that NUM with the existing numbers in the Trie, we need to get maximum, so we alwyas check if there's a bit opposite to the NUM's bit
            // ex: if NUM's bit is 0, we need 1, cuz when XORed we get 1 again
            // ex: if NUM's bit is 1, we need 0, cuz when XORed we get 1 again
            if(node->containsKey(1 - bit)){
                // 1 contains 00...000001 so 1 is left shifted i times to set it as 0001...00 1 is now at ith poistion
                maxNum = maxNum | (1 << i);
                node = node->getLink(1 - bit);
            }
            else{
                // move to the next link to find the next bit;
                node = node->getLink(bit);
            }
        }
        return maxNum;
    }
};



class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<int>ans(queries.size(), -1);

        // map<int, vector<int>>sortQueries;

        for(int i=0; i<queries.size(); i++){
            queries[i].push_back(i);
        }
        
        sort(queries.begin(), queries.end(), [](vector<int>a, vector<int>b){
            return a[1] < b[1];
        });


        // inserting all nums into the TRIE DS
        // TIME COMPLEXITY IF O(N * 32) (n = nums.size(), and inserting them in TRIE is 32)
        Trie trie;
        int i = 0;
        for(auto q: queries){
            int x = q[0];
            int m = q[1];
            int index = q[2];

            int start_i = i;
            while(i<n && nums[i] <= m){
                trie.insert(nums[i]);
                i++;
            }
            if(i != 0){ // only if Trie has something
                ans[index] = trie.getMax(x);
            }
            else{
                // ans[index] = -1;
                // not needed already set
            }
        }
        

        return ans;
    }
};