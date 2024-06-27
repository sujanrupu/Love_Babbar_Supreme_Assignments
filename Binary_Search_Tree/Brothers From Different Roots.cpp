class Solution
{
public:
    void inorder(Node *root, vector<int>& arr) {
        if(!root)   return ;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

    int countPairs(Node* root1, Node* root2, int x)
    {
        vector<int>a, b;
        inorder(root1, a);
        inorder(root2, b);
        int ans = 0;
        for(int i = 0; i < a.size(); i++) {
            for(int j = 0; j < b.size(); j++) {
                if(a[i] + b[j] == x)    ans++;
            }
        }
        return ans;
    }
};
