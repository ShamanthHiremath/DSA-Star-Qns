class Solution {
public:
    void countPaths(Node* root, int k, int currentSum, std::unordered_map<int, int>& pathSums, int& totalCount) {
        if (!root) return;
        
        currentSum += root->data;
        
        // If there exists a prefix sum such that (currentSum - k), it means there exists a path
        // with the desired sum ending at the current node
        if (pathSums.find(currentSum - k) != pathSums.end()) {
            totalCount += pathSums[currentSum - k];
        }
        
        // Increment the count of currentSum in the hashmap
        pathSums[currentSum]++;
        
        // Recur for left and right subtrees
        countPaths(root->left, k, currentSum, pathSums, totalCount);
        countPaths(root->right, k, currentSum, pathSums, totalCount);
        
        // Backtrack: Decrement the count of currentSum after processing
        pathSums[currentSum]--;
    }

    int sumK(Node* root, int k) {
        if (!root) return 0;
        
        std::unordered_map<int, int> pathSums;
        pathSums[0] = 1; // To account for the case where the path sum equals k from the root itself
        
        int totalCount = 0;
        countPaths(root, k, 0, pathSums, totalCount);
        
        return totalCount;
    }
};


class Solution{
  public:
  
  void solve(Node* root, int k, int &total, vector<int>&path){
      if(root==NULL){
          return ;
      }
      
      path.push_back(root->data);
      
      solve(root->left, k, total, path);
      solve(root->right, k, total, path);
     
      int sum=0;
      
      for(int i=path.size()-1; i>=0; i--){
          sum+=path[i];
          if(sum==k){
              total++;
          }
      }
      
      path.pop_back();
      
  }
    int sumK(Node *root,int k)
    {
        int total=0;
        vector<int>path;
        solve(root, k, total, path);
        return total;
    }
};