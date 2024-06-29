class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(int i = 0; i < s.length(); i++) {
            if(s[i]=='[')
                st.push(s[i]);
            else if(st.size()!=0 && st.top()=='[')
                st.pop();
        }
        int ans = st.size();
        if(ans % 2 == 0)    return (ans/2);
        else    return ((ans+1)/2);
    }
};
