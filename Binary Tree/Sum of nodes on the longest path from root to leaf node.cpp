class Solution
{
public:
    pair<int, int> solve(Node *root) {
        if(!root)
            return {0, 0};
        auto left = solve(root->left);
        auto right = solve(root->right);
        int sum = root->data;
        if(left.first == right.first)
            sum += left.second > right.second ? left.second : right.second;
        else if(left.first > right.first)
            sum += left.second;
        else
            sum += right.second;
        pair<int, int> ans = {max(left.first, right.first) + 1, sum};
        return ans;
    }
    
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        if(!root)
            return 0;
        auto ans = solve(root);
        return ans.second;
    }
};
