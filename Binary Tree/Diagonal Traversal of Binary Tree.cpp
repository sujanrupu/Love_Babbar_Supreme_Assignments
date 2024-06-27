vector<int> diagonal(Node *root)
{
   vector<int>ans;
   if(!root)    return ans;
   queue<Node*>q;
   q.push(root);
   while(!q.empty()) {
       Node *front = q.front(); q.pop();
       while(front) {
           ans.push_back(front->data);
           if(front->left)  q.push(front->left);
           front = front->right;
       }
   }
   return ans;
}
