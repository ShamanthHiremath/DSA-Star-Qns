class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // total no of subsets = 2^n
        int subsets = 1<<nums.size();
        vector<vector<int>>ans;

        /*
        Ex: for a set with 3 elements, the subsets will be:
        index included -> elements included
        000 -> {}
        001 -> {3}
        010 -> {2}
        011 -> {2,3}
        100 -> {1}
        101 -> {1,3}
        110 -> {1,2}
        111 -> {1,2,3}
        */

        for(int num=0; num<subsets; num++){
            vector<int>temp;
            for(int i=0; i<nums.size(); i++){
                // checks if the ith bit is set, if yes then push/incl the element in that index 
                if(num & (1<<i)){
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};