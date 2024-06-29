class Solution {
public:
    int solve(string &a, string &b, int i, int j, vector<vector<int>>& dp) {
        if(i >= a.length() || j >= b.length())  return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        int ans = 0;
        if(a[i] == b[j])
            ans = 1 + solve(a, b, i+1, j+1, dp);
        else
            ans = max(solve(a, b, i+1, j, dp), solve(a, b, i, j+1, dp));
        return dp[i][j] = ans;
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string a = s;
        reverse(s.begin(), s.end());
        string b = s;
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(a, b, 0, 0, dp);
    }
};
