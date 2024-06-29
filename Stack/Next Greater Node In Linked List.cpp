class Solution {
public:
    int findMaxi(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n);
        for(int i=0; i<n; i++)
            ans[i] = arr[i];
        sort(ans.begin(), ans.end());
        int res = ans[n-1];
        return res;
    }

    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        ListNode *curr = head;
        while(curr) {
            ans.push_back(curr->val);
            curr = curr->next;
        }
        int maxi = findMaxi(ans) + 1;
        stack<int>st;
        st.push(maxi);
        vector<int>final(ans.size());
        for(int i=ans.size()-1; i>=0; i--) {
            if(!st.empty()) {
                while(!st.empty() && st.top() <= ans[i]) 
                    st.pop();
            }
                if(st.top() == maxi)
                    final[i] = 0;
                else
                    final[i] = st.top();
                st.push(ans[i]);
        }

        return final;
    }
};
