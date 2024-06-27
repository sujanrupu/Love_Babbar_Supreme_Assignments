class Solution {
public:
    void inorder(TreeNode *root, vector<int>& arr) {
        if(!root)   return ;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int>arr;
        inorder(root, arr);
        int ans = 0;
        for(int i = 0; i <= arr.size(); i++) {
            if(arr[i] >= low && arr[i] <= high) ans += arr[i];
        }
        return ans;
    }
};
