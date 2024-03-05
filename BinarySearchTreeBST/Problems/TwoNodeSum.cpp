void inorder(BinaryTreeNode<int>* root, vector<int>&arr){
    if(root==NULL){
        return ;
    }
    inorder(root->left, arr);
    //push elements
    arr.push_back(root->data);
    
    inorder(root->right, arr);

}

bool twoSum(vector<int>&arr, int target){
    int i=0, j=arr.size()-1;
    while(i<j){
        int sum=arr[i]+arr[j];
        if(sum==target){
            return true;
        }
        else if(sum>target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
    vector<int> arr;
    inorder(root, arr);
    return twoSum(arr, target);
}