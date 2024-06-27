class Solution {
  public:
    int solve(Node *root) {
        if(!root)   return 0;
        if(!root->left && !root->right) {
            int temp = root->data;
            root->data = 0;
            return temp;
        }
        int temp = root->data;
        int left = solve(root->left), right = solve(root->right);
        root->data = left + right;
        int ans = root->data + temp;
        return ans;
    }
    
    void toSumTree(Node *node)
    {
        solve(node);
    }
};
