class Solution {
public:
    bool isNum(char ch) {
        if(ch >= '0' && ch <= '9')  return true;
        return false;
    }

    string decodeString(string s) {
        stack<char>st;
        for(int i = 0; i < s.length(); i++) {
            if(s[i]!=']')   st.push(s[i]);
            else {
                string temp = "";
                while(st.top() != '[') {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                string nums = "";
                while(!st.empty() && isNum(st.top())) {
                    nums = st.top() + nums;
                    st.pop();
                }
                int k = stoi(nums);
                while(k--) {
                    for(int j = 0; j < temp.length(); j++)
                        st.push(temp[j]);
                }
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
