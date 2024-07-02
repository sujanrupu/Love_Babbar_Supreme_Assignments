class Solution {
public:
    void solve(vector<int>& v, int& n, int& ans, int curr) {
        if(curr == n + 1) {
            ++ans;
            return ;
        }
        for(int i=1; i<=n; i++) {
            if(v[i] == 0 && (curr % i == 0 || i % curr == 0)) {
                v[i] = curr;
                solve(v, n, ans, curr + 1);
                v[i] = 0;
            }
        }
    }

    int countArrangement(int n) {
        vector<int>v(n + 1);
        int ans = 0;
        solve(v, n, ans, 1);
        return ans;
    }
};
