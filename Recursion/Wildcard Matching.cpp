class Solution {
public:
    bool allStars(string &s, int end) {
        for(int i = 0; i <= end; i++) {
            if(s[i]!='*')   return false;
        }
        return true;
    }

    bool solve(string &s, string &p, int i, int j, vector<vector<int>>& dp) {
        if(i < 0 && j < 0)  return true;
        if(i < 0 && j >= 0) return allStars(p, j);
        if(i >= 0 && j < 0) return false;
        if(dp[i][j]!=-1)    return dp[i][j];
        if(s[i] == p[j] && p[j] == '?')
            return dp[i][j] = solve(s, p, i-1, j-1, dp);
        else if(p[j] == '*')
            return dp[i][j] = solve(s, p, i-1, j, dp) || solve(s, p, i, j-1, dp);
        else    return false;
    }

    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return solve(s, p, m-1, n-1, dp);
    }
};
