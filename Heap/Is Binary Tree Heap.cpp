class Solution {
  public:
    int getLength(Node *root) {
        if(!root)   return 0;
        return 1+getLength(root->left)+getLength(root->right);
    }

    bool isCompleteTree(Node* root) {
        if(!root)   return false;
        int length = getLength(root);
        queue<Node*>q;
        q.push(root);
        int count = 0;
        while(!q.empty()) {
            Node *front = q.front();    q.pop();
            if(!front)  break;
            count++;
            q.push(front->left);
            q.push(front->right);
        }
        if(count < length)  return false;
        return true;
    }
    
    bool maxOrder(Node *root) {
        if(!root)   return false;
        bool ans = false;
        if(!root->left && !root->right) ans = true;
        if(root->left && !root->right)  ans = root->data > root->left->data;
        if(root->left && root->right)   ans = root->data > root->left->data && root->data > root->right->data;
    }
    
    bool isHeap(struct Node* root) {
        if(!root)   return false;
        return isCompleteTree(root) && maxOrder(root);
    }
};
