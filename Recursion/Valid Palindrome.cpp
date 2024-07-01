class Solution {
public:
    bool isChar(char ch) {
        if(ch>='a' && ch<='z' || ch>='A' && ch<='Z' || ch >= '0' && ch <= '9')    return true;
        return false;
    }

    char to_small(char ch) {
        if(ch >= 'A' && ch <= 'Z')  ch = ch - 'A' + 'a';
        return ch;
    }

    bool check(string &s) {
        int start = 0, end = s.length() - 1;
        while(start < end) {
            if(s[start]!=s[end])    return false;
            start++;    end--;
        }
        return true;
    }

    bool isPalindrome(string s) {
        string str = "";
        for(int i = 0; i < s.length(); i++) {
            if(isChar(s[i]))    str.push_back(to_small(s[i]));
        }
        return check(str);
    }
};
