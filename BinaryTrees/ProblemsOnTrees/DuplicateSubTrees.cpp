class Solution {
  public:
    string preOrder(Node *root, vector<Node*> &ans, unordered_map<string,int> &mp){
        string temp = "";
        if(root == NULL)
            return "#";
        temp += to_string(root->data);
        temp += preOrder(root->left,ans,mp);
        temp += preOrder(root->right,ans,mp);
        if(mp[temp] == 1)
            ans.push_back(root);
        mp[temp]++;
        return temp;
        
    }
    vector<Node*> printAllDups(Node* root) {
        vector<Node*> ans;
        unordered_map<string,int> mp;
        preOrder(root,ans,mp);
        return ans;
    }
};
