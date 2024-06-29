class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if(!head)   return 0;
        ListNode* slow = head, *fast = head->next, *newLastNode = 0;

        int sum = 0;

        while(fast) {
            if(fast->val != 0) {
                sum += fast->val;
            }
            else {
                slow->val = sum;
                newLastNode = slow;
                slow = slow->next;
                sum = 0;
            }
            fast = fast->next;
        }

        ListNode* temp = newLastNode->next;
        newLastNode->next = 0;

        while(temp) {
            ListNode* next = temp->next;
            delete temp;
            temp = next;
        }
        return head;
    }
};
