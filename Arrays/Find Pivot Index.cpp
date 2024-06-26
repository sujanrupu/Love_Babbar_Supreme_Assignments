class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int sum1 = 0, sum2 = 0;
            for(int j = 0; j < i; j++)  sum1 += nums[j];
            for(int j = i + 1; j < n; j++)  sum2 += nums[j];
            if(sum1 == sum2)    return i;
        }
        return -1;
    }
};
