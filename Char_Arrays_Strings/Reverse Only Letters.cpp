class Solution {
public:
    bool isChar(char ch) {
        if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')    return true;
        return false;
    }

    string reverseOnlyLetters(string s) {
        stack<char>st;
        string ans = "";
        for(int i = 0; i < s.length(); i++) {
            if(isChar(s[i]))    st.push(s[i]);
        }

        for(int i = 0; i < s.length(); i++) {
            if(!isChar(s[i])) ans.push_back(s[i]);
            else {
                ans.push_back(st.top());    st.pop();
            }
        }
        return ans;
    }
};
