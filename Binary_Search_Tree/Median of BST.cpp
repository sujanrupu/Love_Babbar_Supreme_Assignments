void inorder(Node *root, vector<float>& arr) {
        if(!root)   return ;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

float findMedian(struct Node *root)
{
      vector<float>arr;
      inorder(root, arr);
      if(arr.size() % 2 == 1)   return arr[arr.size()/2];
      float a = arr[(arr.size()/2) - 1];
      float b = arr[arr.size()/2];
      float ans = (a + b)/2;
      return ans;
}
