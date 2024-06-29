class Solution {
public:
    int solve(string &s, string &t, int i, int j, vector<vector<int>>& dp) {
        if(j >= t.length()) return 1;
        if(i >= s.length()) return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        int ans = 0;
        if(s[i] == t[j])
            ans += solve(s, t, i+1, j+1, dp);
        ans += solve(s, t, i+1, j, dp);
        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return solve(s, t, 0, 0, dp);
    }
};
