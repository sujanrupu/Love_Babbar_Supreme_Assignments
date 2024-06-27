class Solution {
public:
    int findMinDifference(vector<string>& tp) {
        vector<int>arr;
        for(int i = 0; i < tp.size(); i++) {
            int a = stoi(tp[i].substr(0, 2));
            int b = stoi(tp[i].substr(3, 2));
            int total = (a * 60) + b;
            arr.push_back(total);
        }
        sort(arr.begin(), arr.end());
        int ans = INT_MAX;
        int n = arr.size();
        for(int i = 0; i < arr.size()-1; i++)
            ans = min(ans, arr[i+1]-arr[i]);
        ans = min(ans, arr[0] + (1440 - arr[n-1]));
        return ans;
    }
};
