class Solution {
public:
    vector<int> asteroidCollision(vector<int>& at) {
        stack<int>st;
        for(int i = 0; i < at.size(); i++) {
            if(st.empty() || (at[i]>0 && st.top()>0) || (at[i]<0 && st.top()<0))
                st.push(at[i]);
            else {
                int isEqual = 0;
                while(!st.empty() && isEqual == 0) {
                    if(abs(at[i]) == abs(st.top())) {
                        st.pop();
                        isEqual++;
                    }
                    else if(abs(at[i]) > abs(st.top())) 
                        st.pop();
                    else 
                        isEqual++;
                }
                if(isEqual == 0)    st.push(at[i]);
            }
        }
        vector<int>ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
