class Solution {
public:
    bool solve(string &s, vector<string>& wordDict, int index, vector<int>& dp) {
        if(index >= s.length()) return 1;
        if(dp[index]!=-1)   return dp[index];
        string ans = "";
        bool flag = false;
        for(int i = index; i < s.length(); i++) {
            ans += s[i];
            for(auto it : wordDict) {
                if(ans == it)
                    flag = flag || solve(s,wordDict, i+1, dp);
            }
        }
        return dp[index] = flag;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int>dp(n+1, -1);
        return solve(s, wordDict, 0, dp);
    }
};
