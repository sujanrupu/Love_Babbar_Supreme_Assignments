class Solution {
public:
    int solve(vector<int>& sat, int index, int time, vector<vector<int>>& dp) {
        if(index >= sat.size()) return 0;
        if(dp[index][time]!=-1) return dp[index][time];
        int incl = sat[index]*time + solve(sat, index+1, time+1, dp);
        int excl = 0 + solve(sat, index+1, time, dp);
        return dp[index][time] = max(incl, excl);
    }

    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(), sat.end());
        int n = sat.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return solve(sat, 0, 1, dp);
    }
};
