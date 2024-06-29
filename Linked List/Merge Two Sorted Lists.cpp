class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        if(list1->val > list2->val) {
            ListNode *temp = list1;
            list1 = list2;
            list2 = temp;
        }
        ListNode* ans = list1;
        while(list1 && list2) {
            ListNode *p = list1;
            while(list1 && list1->val <= list2->val) {
                p = list1;
                list1 = list1->next;
            }
            p->next = list2;
            ListNode *temp = list1;
            list1 = list2;
            list2 = temp;
        }
        return ans;
    }
};
