class Solution {
public:
    bool solve(string &s1, string &s2, string &s3, int i, int j, vector<vector<int>>& dp) {
        if(i+j == s3.length())  return true;
        if(dp[i][j]!=-1)    return dp[i][j];
        bool ans = false;
        if(s1[i] == s3[i+j])
            ans = ans | solve(s1, s2, s3, i+1, j, dp);
        if(s2[j] == s3[i+j])
            ans = ans | solve(s1, s2, s3, i, j+1, dp);
        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if(m + n != s3.length())    return false;
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return solve(s1, s2, s3, 0, 0, dp);
    }
};
