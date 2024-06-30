class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(), a.end());
        long long ans = 1e9;
        for(int i = 0; i <= (n - m); i++) {
            long long diff = a[(i+m)-1] - a[i];
            ans = min(diff, ans);
        }
        return ans;
    }   
};
