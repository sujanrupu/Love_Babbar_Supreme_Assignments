class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>>v;
        int count = 1;
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] == nums[i+1])    count++;
            else {
                v.push_back({nums[i], count});
                count = 1;
            }
        }
        v.push_back({nums[nums.size()-1], count});
        sort(v.begin(), v.end(), cmp);
        vector<int>ans;
        for(int i = 0; i < k; i++)
            ans.push_back(v[i].first);
        return ans;
    }
};
