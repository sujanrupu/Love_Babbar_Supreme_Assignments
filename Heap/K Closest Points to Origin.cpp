class Solution {
public:
    static bool cmp(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
        return a.second < b.second;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<pair<int, int>, int>>v;
        for(int i = 0; i < points.size(); i++) {
            int distX = pow((points[i][0] - 0), 2);
            int distY = pow((points[i][1] - 0), 2);
            int dist = distX + distY;
            v.push_back({{points[i][0], points[i][1]}, dist});
        }
        sort(v.begin(), v.end(), cmp);
        vector<vector<int>>ans;
        for(int i = 0; i < k; i++)  {
            vector<int>arr;
            arr.push_back(v[i].first.first);
            arr.push_back(v[i].first.second);
            ans.push_back(arr);
        }
        return ans;
    }
};
