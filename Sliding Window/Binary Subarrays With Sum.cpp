class Solution {
public:
    int solve(vector<int>& nums, int goal) {
        if(goal < 0)    return 0;
        int n = nums.size(), i = 0, j = 0, ans = 0;
        while(j < n) {
            goal -= nums[j];
            while(goal < 0) {
                goal += nums[i];
                i++;
            }
            ans += (j - i + 1);
            j++;
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal - 1);
    }
};
