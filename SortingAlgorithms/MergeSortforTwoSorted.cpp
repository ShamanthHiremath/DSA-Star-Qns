//nums1 = [1,2,3,7,8,9], m = 6, nums2 = [2,5,6], n = 3
//Output: [1,2,2,3,5,6,7,8,9]
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0,k=0;
        vector<int> nums3(m+n);
        while(i<m&&j<n){
            if(nums1[i]<nums2[j]){
                nums3[k]=nums1[i];
                //cout<<nums1[k]<<",";
                k++;
                i++;
            }
            else{
                nums3[k]=nums2[j];
                //cout<<nums1[k]<<",";
                k++;
                j++;
            }
        }
        while(i<m){
            nums3[k]=nums1[i];
            //cout<<nums1[k]<<",";
            k++;
            i++;
        }
        while(j<n){
            nums3[k]=nums2[j];
            //cout<<nums1[k]<<",";
            k++;
            j++;
        }
    }
};
//nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
//Output: [1,2,2,3,5,6]
class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1, k=m+n-1;
        while(i>=0&&j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                //cout<<nums1[k]<<",";
                k--;
                i--;
            }
            else{
                nums1[k]=nums2[j];
                //cout<<nums1[k]<<",";
                k--;
                j--;
            }
        }
        while(i>=0){
            nums1[k]=nums1[i];
           // cout<<nums1[k]<<",";
            k--;
            i--;
        }
        while(j>=0){
            nums1[k]=nums2[j];
            //cout<<nums1[k]<<",";
            k--;
            j--;
        }
    }
};
