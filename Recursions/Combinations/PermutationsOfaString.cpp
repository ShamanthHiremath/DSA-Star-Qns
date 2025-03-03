class Solution {
    private:
        void solve(vector<vector<int>>&ans, vector<int> nums,  int index ){
            if(index>=nums.size()){
                ans.push_back(nums);
                return ;
            }
            for(int i=index; i<nums.size(); i++){
                // do the swap
                swap(nums[i], nums[index]);
                // call for next fn
                solve(ans, nums, index+1);
                // undo the swap
                swap(nums[i], nums[index]);
            }
        }
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            int index=0;
            if(nums.size()==0)return {};
            vector<vector<int>>ans;
            //vector<int> output;
            solve(ans, nums, index);
            return ans;
            
        }
};

void perm(char *list, int i,int n)
{
int j,temp;
if(i==n)        {
              for(j=0;j<=n;j++)
                         printf("%c",list[j]);
   printf("  ");
   }
   else
   {
   for(j=i;j<=n;j++)
   {
      SWAP(list[i],list[j], temp);
      perm(list,i+1,n);
      SWAP(list[i],list[j],temp);
  }
}
}
