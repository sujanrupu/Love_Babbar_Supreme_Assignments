class Solution {
public:
    int ans = 0;

    void solve(TreeNode *root, long long target) {
        if(!root)   return ;
        if(root->val == target) ans++;
        solve(root->left, target - root->val);
        solve(root->right, target - root->val);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root)   return 0;
        if(root) {
            solve(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ans;
    }
};
