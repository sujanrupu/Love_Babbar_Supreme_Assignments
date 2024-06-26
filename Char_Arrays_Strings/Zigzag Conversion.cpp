class Solution {
public:
    string convert(string s, int numRows) {
        int i = 0, n = s.length();
        if(numRows == 1)    return s;
        bool direction = 1;
        vector<string>str(numRows);
        int row = 0;
        while(true) {
            if(direction) {
                while(i < s.length() && row < numRows) {
                    str[row++].push_back(s[i++]);
                }
                row = numRows - 2;
            }
            else {
                while(i < s.length() && row >= 0) {
                    str[row--].push_back(s[i++]);
                }
                row = 1;
            }
            if(i >= s.length()) break;
            direction = !direction;
        }
        string ans = "";
        for(int i = 0; i < str.size(); i++)
            ans += str[i];
        return ans;
    }
};
