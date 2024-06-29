class Solution {
public:
    int solve(vector<int>& prices, int index, int buy, vector<vector<int>>& dp) {
        if(index >= prices.size())  return 0;
        if(dp[index][buy]!=-1)  return dp[index][buy];
        int profit = 0;
        if(buy) {
            int buy = -prices[index] + solve(prices, index+1, 0, dp);
            int skip = 0 + solve(prices, index+1, 1, dp);
            profit = max(buy, skip);
        }
        else {
            int sell = prices[index] + solve(prices, index+1, 1, dp);
            int skip = 0 + solve(prices, index+1, 0, dp);
            profit = max(sell, skip);
        }
        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return solve(prices, 0, 1, dp);
    }
};
