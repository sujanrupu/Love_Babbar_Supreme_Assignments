class Solution {
public:
    ListNode *findMid(ListNode *head) {
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *solve(ListNode *a, ListNode *b) {
        if(!a)  return b;
        if(!b)  return a;
        ListNode *ans = new ListNode(-1);
        ListNode * temp = ans;
        while(a && b) {
            if(a->val < b->val) {
                temp->next = a;
                temp = a;
                a = a->next;
            }
            else {
                temp->next = b;
                temp = b;
                b = b->next;
            }
        }
        while(a) {
            temp->next = a;
            temp = a;
            a = a->next;
        }
        while(b) {
            temp->next = b;
            temp = b;
            b = b->next;
        }
        ans = ans->next;
        return ans;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)   return head;
        ListNode *a = head;
        ListNode *mid = findMid(head);
        ListNode *b = mid->next;
        mid->next = NULL;
        a = sortList(a);
        b = sortList(b);
        ListNode *ans = solve(a, b);
        return ans;
    }
};
