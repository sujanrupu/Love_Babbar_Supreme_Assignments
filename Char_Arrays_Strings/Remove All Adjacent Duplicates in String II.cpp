class Solution {
public:
    string removeDuplicates(string s, int k) {
        string ans = "";
        stack<char>st;
        for(int i = 0; i < s.length(); i++) {
            if(st.empty())  st.push(s[i]);
            else if(s[i] != st.top())   st.push(s[i]);
            else {
                string str = "";
                int count = 0;
                while(!st.empty() && st.top() == s[i] && count < k-1) {
                    str.push_back(st.top());
                    count++;
                    st.pop();
                }
                if(count < k-1) {
                    for(int j = 0; j < str.length(); j++)   st.push(str[i]);
                    st.push(s[i]);
                }
            }
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
