class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int srow=0, scol=0, erow=matrix.size()-1, ecol=matrix[0].size()-1;
        int count=0, total=matrix.size()*matrix[0].size();
        while(count<total){
            for(int j=scol; count<total && j<=ecol;j++){
                ans.push_back(matrix[srow][j]);
                count++;
            }
            srow++;
            for(int i=srow; count<total && i<=erow;i++){
                ans.push_back(matrix[i][ecol]);
                count++;
            }
            ecol--;
            for(int j=ecol; count<total && j>=scol;j--){
                ans.push_back(matrix[erow][j]);
                count++;
            }
            erow--;
            for(int i=erow; count<total && i>=srow;i--){
                ans.push_back(matrix[i][scol]);
                count++;
            }
            scol++;
        }
        return ans;       
    }
};