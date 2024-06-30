class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<char>st;
        for(int i = 0; i < s.length(); i++) {
            if(k > 0) {
                while(st.size()>0 && st.top()>s[i]) {
                    st.pop();
                    k--;
                    if(k == 0)  break;
                }
            }
            st.push(s[i]);
        }
        if(k>0) {
            while(!st.empty() && k>0) {
                st.pop();
                k--;
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        while(ans.length()>0 && ans.back() == '0') 
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans == "" ? "0" : ans;
    }
};
