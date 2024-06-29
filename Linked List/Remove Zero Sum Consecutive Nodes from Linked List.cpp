class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head || (!head->next && head->val == 0))   return NULL;
        vector<int>arr;
        ListNode *curr = head;
        while(curr) {
            arr.push_back(curr->val);
            curr = curr->next;
        }
        stack<int>st;
        for(int i = 0; i < arr.size(); i++) {
            if(st.empty())  st.push(arr[i]);
            else if(arr[i] != 0) {
                vector<int>temp;
                int sum = arr[i] + st.top();
                temp.push_back(arr[i]);
                temp.push_back(st.top());
                st.pop();
                while(!st.empty() && sum != 0) {
                    sum += st.top();
                    temp.push_back(st.top());
                    st.pop();
                }
                if(sum != 0) {
                    reverse(temp.begin(), temp.end());
                    for(int i = 0; i < temp.size(); i++)
                        st.push(temp[i]);
                }
            }
        }
        vector<int>ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        ListNode dummy(0);
        curr = &dummy;
        for (int val : ans) {
            curr->next = new ListNode(val);
            curr = curr->next;
        }
        
        return dummy.next;
    }
};
