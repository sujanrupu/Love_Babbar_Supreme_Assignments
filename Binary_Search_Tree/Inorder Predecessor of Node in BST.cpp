Node* findPredecessor(Node* root, Node* p) {
    Node *curr = root, *ans = NULL;
	while(curr) {
		if(curr->data < p->data) {
			ans = curr;
			curr = curr->right;
		}
		else
				curr = curr->left;
	}
	return ans;
}
