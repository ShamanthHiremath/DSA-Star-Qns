/*
421. Maximum XOR of Two Numbers in an Array

https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
https://takeuforward.org/data-structure/maximum-xor-of-two-numbers-in-an-array/

Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

Example 1:
Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.

Example 2:
Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
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
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        
        // inserting all nums into the TRIE DS
        // TIME COMPLEXITY IF O(N * 32) (n = nums.size(), and inserting them in TRIE is 32)
        Trie trie;
        for(int num: nums){
            trie.insert(num);
        }

        // applying that GET MAX funcion to get the MAXIMUM MOST XORed NUMS
        

        // TIME COMPLEXITY IS O(N * 32) (n = nums.size(), and inserting them in TRIE is 32)
        int maxi = 0;
        for(int num: nums){
            maxi = max(maxi, trie.getMax(num));
        }

        return maxi;
    }
};