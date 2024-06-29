Node *solve(Node *a, Node *b)  {
    if(!a)  return b;
    if(!b)  return a;
    Node *ans = NULL;
    if(a->data < b->data) {
        ans = a;
        a->bottom = solve(a->bottom, b);
    }
    else {
        ans = b;
        b->bottom = solve(a, b->bottom);
    }
    return ans;
}
    
Node *flatten(Node *root) {
    if(!root)   return NULL;
    Node *ans = solve(root, flatten(root->next));
    return ans;
}
