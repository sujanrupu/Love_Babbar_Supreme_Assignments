class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, int>mp1, mp2;
        for(int i = 0; i < s.length(); i++) {
            if(mp1[s[i]] && mp1[s[i]]!=t[i])    return false;
            if(mp2[t[i]] && mp2[t[i]]!=s[i])    return false;
            mp1[s[i]]=t[i];
            mp2[t[i]]=s[i];
        }
        return true;
    }
};
