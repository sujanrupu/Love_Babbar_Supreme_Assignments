class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int index, int p1, int p2, vector<vector<int>>& dp, bool isSwap) {
        if(index == nums1.size())
            return 0;
        if(dp[index][isSwap]!=-1)   return dp[index][isSwap];
        int swap = INT_MAX, noswap = INT_MAX;
        if(p1<nums2[index] && p2<nums1[index])
            swap = 1 + solve(nums1, nums2, index+1, nums2[index], nums1[index], dp, 1);
        if(p1<nums1[index] && p2<nums2[index])
            noswap = solve(nums1, nums2, index+1, nums1[index], nums2[index], dp, 0);
        return dp[index][isSwap] = min(swap, noswap);
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return solve(nums1, nums2, 0, -1, -1, dp, 0);
    }
};
