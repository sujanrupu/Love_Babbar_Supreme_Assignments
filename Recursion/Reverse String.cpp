class Solution {
public:
    void reverseString(vector<char>& s) {
        string str = "";
        for(int i = 0; i < s.size(); i++)   str.push_back(s[i]);
        reverse(str.begin(), str.end());
        for(int i = 0; i < str.length(); i++)   s[i] = str[i];
    }
};
