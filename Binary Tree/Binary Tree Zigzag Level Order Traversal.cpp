class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)   return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int>temp;
            for(int i = 0; i < size; i++) {
                TreeNode *front = q.front();    q.pop();
                temp.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right)    q.push(front->right);
            }
            ans.push_back(temp);
        }
        for(int i = 0; i < ans.size(); i++) {
            if(i%2 == 1)
                reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};
