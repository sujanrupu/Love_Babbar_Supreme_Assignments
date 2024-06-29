class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *curr = head;
        vector<int>arr;
        while(curr) {
            arr.push_back(curr->val);
            curr = curr->next;
        }
        int a = arr[k-1];
        reverse(arr.begin(), arr.end());
        int b = arr[k-1];
        curr = head;
        arr[k-1] = a;
        reverse(arr.begin(), arr.end());
        arr[k-1] = b;
        for(int i = 0; i < arr.size(); i++) {
            curr->val = arr[i];
            curr = curr->next;
        }
        return head;
    }
};
