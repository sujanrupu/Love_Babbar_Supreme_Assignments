class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1;
        int n = chars.size();
        string ans = "";
        for(int i = 0; i < n-1; i++) {
            if(chars[i] == chars[i+1])  count++;
            else if(count > 1) {
                ans.push_back(chars[i]);
                ans += to_string(count);
                count = 1;
            }
            else ans.push_back(chars[i]);
        }
        if(count > 1) {
            ans.push_back(chars[n-1]);
            ans += to_string(count);
        }
        else
            ans.push_back(chars[n-1]);
        for(int i = 0; i < ans.length(); i++)
            chars[i] = ans[i];
        return ans.size();
    }
};
