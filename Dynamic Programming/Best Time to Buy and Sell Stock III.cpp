class Solution {
public:
    int solve(vector<int>& prices, int index, int buy, int limit, vector<vector<vector<int>>>& dp) {
        if(index >= prices.size() || limit == 0)  return 0;
        if(dp[index][buy][limit]!=-1)  return dp[index][buy][limit];
        int profit = 0;
        if(buy) {
            int buy = -prices[index] + solve(prices, index+1, 0,limit, dp);
            int skip = 0 + solve(prices, index+1, 1, limit, dp);
            profit = max(buy, skip);
        }
        else {
            int sell = prices[index] + solve(prices, index+1, 1, limit - 1, dp);
            int skip = 0 + solve(prices, index+1, 0, limit, dp);
            profit = max(sell, skip);
        }
        return dp[index][buy][limit] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(prices, 0, 1, 2, dp);
    }
};
