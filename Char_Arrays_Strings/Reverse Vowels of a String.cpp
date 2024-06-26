class Solution {
public:
    bool vowel(char ch) {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') return true;
        return false;
    }

    string reverseVowels(string s) {
        stack<char>st;
        for(int i = 0; i < s.length(); i++) {
            if(vowel(s[i])) st.push(s[i]);
        }
        string ans = "";
        for(int i = 0; i < s.length(); i++) {
            if(vowel(s[i])) {
                ans.push_back(st.top());    st.pop();
            }
            else    ans.push_back(s[i]);
        }
        return ans;
    }
};
