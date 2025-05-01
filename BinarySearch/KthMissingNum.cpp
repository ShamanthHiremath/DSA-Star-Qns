/*
1539. Kth Missing Positive Number

https://leetcode.com/problems/kth-missing-positive-number/

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array. 

Example 1:
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Example 2:
Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s = 0;
        int e = arr.size()-1;
        int mid;

        while(s<=e){
            mid = s + (e-s)/2;

            if(arr[mid] - (mid + 1) < k){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }

        //  e and s cross each other and look like
        //  .... e s .... 
        // e indicates the position of actual number

        return k + e + 1;
    }
};

/*
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(int i=0; i<arr.size(); i++){
            // this line says the number arr[i] <= k means that it is one among the range of numbers 0 to k, but it has occupied the space so we increease k by 1, k++
            if(arr[i] <= k){
                k++;
            }
            // when we find a number > k, we can mean that the range has exceeded... so k is itself the inital number
            else{
                break;
            }
        }

        return k;
    }
};
*/