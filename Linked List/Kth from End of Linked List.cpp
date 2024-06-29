class Solution {
  public:
    int getKthFromLast(Node *head, int k) {
        vector<int>arr;
        Node *curr = head;
        while(curr) {
            arr.push_back(curr->data);
            curr = curr->next;
        }
        if(k > arr.size()) return -1;
        reverse(arr.begin(), arr.end());
        return arr[k-1];
    }
};
