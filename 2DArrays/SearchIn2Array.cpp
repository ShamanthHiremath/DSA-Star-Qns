class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int rows=arr.size();
        int col=arr[0].size();
        int r=0;
        int c=col-1;
        while(r<rows && c>=0){
            if(arr[r][c]==target){
                return true;
            }
            if(arr[r][c]>target){
                c--;
            }
            else{
                r++;
            }
        }
        return false;
        
    }
};