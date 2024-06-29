class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp = NULL;
        int n1 = 0, n2 = 0;
        for(temp = headA; temp; temp = temp->next)  n1++;
        for(temp = headB; temp; temp = temp->next)  n2++;
        while(n1 > n2) {
            headA = headA->next;
            n1--;
        }
        while(n2 > n1) {
            headB = headB->next;
            n2--;
        }
        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        if(headA)   return headA;
        return NULL;
    }
};
