class Solution {
public:
    int getLength(ListNode *head) {
        int length = 0; 
        ListNode *curr = head;
        while(curr) {
            length++;
            curr = curr->next;
        }
        return length;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)   return NULL;
        int length = getLength(head);
        if(k % length == 0) return head;
        int rotateK = k % length;
        int newLastNodePos = length - rotateK - 1;
        ListNode *newLastNode = head;
        for(int i = 0; i < newLastNodePos; i++) 
            newLastNode = newLastNode->next;
        ListNode *newHead = newLastNode->next;
        newLastNode->next = NULL;
        ListNode *it = newHead;
        while(it->next)
            it = it->next;
        it->next = head;
        return newHead;
    }
};
