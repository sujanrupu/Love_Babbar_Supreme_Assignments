class Solution {
public:
    TreeNode *solve(vector<int>& arr, int &i, int mini, int maxi) {
        if(i >= arr.size()) return NULL;
        TreeNode *root = NULL;
        if(arr[i] > mini && arr[i] < maxi) {
            root = new TreeNode(arr[i++]);
            root->left = solve(arr, i, mini, root->val);
            root->right = solve(arr, i, root->val, maxi);
        }
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0, mini = INT_MIN, maxi = INT_MAX;
        return solve(preorder, index, mini, maxi);
    }
};
