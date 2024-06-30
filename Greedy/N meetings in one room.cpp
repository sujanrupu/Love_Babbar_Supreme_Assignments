class Solution
{
    public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>>v;
        for(int i = 0; i < n; i++) 
            v.push_back({start[i], end[i]});
        sort(v.begin(), v.end(), cmp);
        int ans = 1, ansEnd = v[0].second;
        for(int i = 1; i < n; i++) {
            if(v[i].first > ansEnd) {
                ans++;
                ansEnd = v[i].second;
            }
        }
        return ans;
    }
};
