class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int start = 0, end = 1;
        set<pair<int, int>>s;
        while(start < nums.size() && end < nums.size()) {
            int diff = nums[end] - nums[start];
            if(diff == k && start != end) {
                s.insert({nums[start], nums[end]}); start++;    end++;  
            }
            else if(diff < k)   end++;
            else    start++;
        }
        return s.size();
    }
};
