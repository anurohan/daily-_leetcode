class Solution {
public:
    void flatten(TreeNode* root) {
        while(root){
            if(root->left){
                TreeNode* curr = root->left;
                while(curr->right) curr = curr->right;
                curr->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};