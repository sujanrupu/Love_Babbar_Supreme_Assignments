class Solution {
public:
    int solve(vector<int>& nums, int target, int index) {
        if(index == nums.size())    return target==0 ? 1 : 0;
        int plus = solve(nums, target+nums[index], index+1);
        int minus = solve(nums, target-nums[index], index+1);
        int ans = plus + minus;
        return ans;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int index = 0;
        return solve(nums, target, index);
    }
};
