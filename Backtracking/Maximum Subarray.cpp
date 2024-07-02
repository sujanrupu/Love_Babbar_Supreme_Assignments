class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), sumMax = nums[0], sumTillNow = nums[0] < 0 ? 0 : nums[0];
        for(int i = 1; i < n; i++) {
            sumMax = max(sumMax, sumTillNow + nums[i]);
            sumTillNow += nums[i];
            if(sumTillNow < 0)  sumTillNow = 0;
        }
        return sumMax;
    }
};
