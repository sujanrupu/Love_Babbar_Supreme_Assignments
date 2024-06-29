class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i = 0; i < s.length(); i++) {
            if(st.empty() || s[i] == 'a' || s[i] == 'b')   st.push(s[i]);
            else {
                if(st.size() >= 2) {
                    char a = st.top(); st.pop();
                    char b = st.top(); st.pop();
                    if(a != 'b' || b != 'a') {
                        st.push(b);
                        st.push(a);
                        st.push(s[i]);
                    }
                }
            }
        }
        if(st.empty())  return true;
        return false;
    }
};
