Node* findSuccessor(Node* root, Node* p) {
    Node *curr = root, *ans = NULL;
	while(curr) {
		if(curr->data > p->data) {
			ans = curr;
			curr = curr->left;
		}
		else
				curr = curr->right;
	}
	return ans;
}
