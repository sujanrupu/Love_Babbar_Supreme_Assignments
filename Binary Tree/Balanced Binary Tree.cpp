class Solution {
public:
    int solve(TreeNode *root) {
        if(!root)   return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        if(left == -1 || right == -1 || abs(left - right) > 1)  return -1;
        int ans = max(left, right) + 1;
        return ans;
    }

    bool isBalanced(TreeNode* root) {
        if(!root)   return true;
        int ans = solve(root);
        if(ans == -1)   return false;
        return true;
    }
};
