class Solution {
public:
    vector<vector<int>> ans;
    void dfs(TreeNode* r,int t,vector<int>&v){
        if(!r) return;
        v.push_back(r->val);
        if(!r->left && !r->right && t==r->val) ans.push_back(v);
        dfs(r->left,t-r->val,v);
        dfs(r->right,t-r->val,v);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        dfs(root,targetSum,v);
        return ans;
    }
};