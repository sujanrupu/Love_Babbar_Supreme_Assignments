class Solution {
public:
    bool check(vector<int>& stalls, int n, int k, int ans) {
        int pos = stalls[0], count = 1;
        for(int i = 1; i < n; i++) {
            if(stalls[i] - pos >= ans) {
                count++;
                pos = stalls[i];
                if(count >= k)  return true;
            }
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int start = 0, end = stalls[n-1] - stalls[0], ans = -1;
        while(start <= end) {
            int mid = start + (end - start)/2;
            if(check(stalls, n, k, mid)) {
                ans = mid;
                start = mid + 1;
            }
            else    end = mid - 1;
        }
        return ans;
    }
};
