class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char>st;
        int n = part.length();
        for(int i = 0; i < s.length(); i++) {
            if(s[i]!=part[n-1] || st.size() < n-1)  st.push(s[i]);
            else {
                string str = "";
                int count = 0;
                while(count < n-1) {
                    str.push_back(st.top());    st.pop();
                    count++;
                }
                reverse(str.begin(), str.end());
                string temp = str;
                temp.push_back(s[i]);
                if(temp != part) {
                    for(int i = 0; i < str.length(); i++)
                        st.push(str[i]);
                    st.push(s[i]);
                }
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans.push_back(st.top());    st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
