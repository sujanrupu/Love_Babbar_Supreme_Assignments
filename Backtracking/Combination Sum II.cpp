class Solution {
public:
    void solve(vector<int>& cd, int index, int target, vector<int>& v, vector<vector<int>>& ans) {
        if(target < 0)  return ;
        if(target == 0) {
            ans.push_back(v);
            return ;
        }
        for(int i = index; i < cd.size(); i++) {
            if(i > index && cd[i] == cd[i-1])   continue;
            v.push_back(cd[i]);
            solve(cd, i+1, target - cd[i], v, ans);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& cd, int target) {
        sort(cd.begin(), cd.end());
        vector<vector<int>>ans;
        vector<int>v;
        solve(cd, 0, target, v, ans);
        return ans;
    }
};
