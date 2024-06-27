class Solution {
public:
    int height(TreeNode *root) {
        if(!root)   return 0;
        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left, right) + 1;
        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)   return 0;
        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        int both = height(root->left) + height(root->right);
        int ans = max(left, max(right, both));
        return ans;
    }
};
