class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)   return NULL;
        vector<int>odd, even;
        ListNode *curr = head;
        int ind = 0;
        while(curr) {
            if(ind % 2 == 1)  odd.push_back(curr->val);
            else if(ind % 2 == 0)   even.push_back(curr->val);
            curr = curr->next;
            ind++;
        }
        curr = head;
        for(int i = 0; i < even.size(); i++) {
            curr->val = even[i];
            curr = curr->next;
        } 
        for(int i = 0; i < odd.size(); i++) {
            curr->val = odd[i];
            curr = curr->next;
        }      
        return head;
    }
};
