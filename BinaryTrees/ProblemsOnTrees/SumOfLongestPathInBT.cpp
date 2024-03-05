class Solution
{
public:

    void solve(Node *root, int sum, int &maxsum, int len, int &maxlen){
        if(root==NULL){
            if(len>maxlen){
                maxlen=len;
                maxsum=sum;
            }
            else if(len==maxlen){
                maxsum=max(sum, maxsum);
            }
            return ;
        }
        
        //sum += root->data;
        
        solve(root->left, sum+root->data, maxsum, len+1, maxlen);
        solve(root->right, sum+root->data, maxsum, len+1, maxlen);

    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int maxlen=0;
        int maxsum=INT_MIN;
        int len=0;
        int sum=0;
        
        solve(root, sum, maxsum, len, maxlen);
        
        return maxsum;
    }
};