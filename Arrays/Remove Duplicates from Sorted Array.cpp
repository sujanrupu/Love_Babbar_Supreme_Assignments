class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>ans;
        int n = nums.size();
        for(int i = 0; i < n-1; i++) {
            if(nums[i]!=nums[i+1])  ans.push_back(nums[i]);
        }
        ans.push_back(nums[n-1]);
        for(int i = 0; i < ans.size(); i++) nums[i] = ans[i];
        return ans.size();
    }
};
