#include <bits/stdc++.h> 
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int>ans;
    int j=0;
    for(;j<mCols;j++){
        if(j%2==0){
            for(int i=0;i<nRows;i++){
            ans.push_back(arr[i][j]);
            }
        }
        else{
            for(int i=nRows-1;i>=0;i--){
            ans.push_back(arr[i][j]);
            }
        }     
    }
    return ans;
}