class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(),nums.end());
        for(int i=0,j=k;i<k/2;i++){
            swap(nums[i],nums[k-i-1]);
        }
        int i=1;
        for(int j=k;j<((nums.size()+k)/2);j++){
            swap(nums[j],nums[nums.size()-i]);
            i++;
        }
    }
    //Cyclic Way of Shifting
    void rotate1(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        for(int i=0;i<nums.size();i++){
            temp[(i+k)%n]=temp[i];
        }
        }
        nums=temp;
    }
};
