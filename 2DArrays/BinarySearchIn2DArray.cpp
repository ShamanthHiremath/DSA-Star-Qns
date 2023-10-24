class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int tar) {
        //ASSUME ALL THE ELEMENTS AS A SINGLE ARRAY WITH r*c-1 ELEMENTS
        int r=arr.size(), c=arr[0].size();
        int s=0, e=c*r-1, mid=(e-s)/2+s;
        
        while(s<=e){
            int element = arr[mid/c][mid%c];
            //ELEMENT IS PRESENT IN mid/c th row AND mid%c th col
            if(element==tar){
                return true;
            }
            else if(tar>element){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=(e-s)/2+s;
        }
        return false;

        
        
    }
};