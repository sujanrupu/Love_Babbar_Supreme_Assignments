class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& ev) {
        sort(ev.begin(), ev.end());
        int n = ev.size();
        vector<int>dp(n, 1);
        for(int i = 0; i < n; i++) {
            int height_x = ev[i][0];
            int width_x = ev[i][1];
            for(int j = 0; j < i; j++) {
                int height_y = ev[j][0];
                int width_y = ev[j][1];
                if(height_y < height_x && width_y < width_x)
                    dp[i] = max(dp[i], 1+dp[j]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
