class Solution{
  public:
    pair<int, int>solve(Node *root) {
        if(!root)   return {0, 0};
        auto left = solve(root->left);
        auto right = solve(root->right);
        int a = root->data + left.second + right.second;
        int b = max(left.first, left.second) + max(right.first, right.second);
        return {a, b};
    }
    int getMaxSum(Node *root) 
    {
        pair<int, int>ans = solve(root);
        return max(ans.first, ans.second);
    }
};
