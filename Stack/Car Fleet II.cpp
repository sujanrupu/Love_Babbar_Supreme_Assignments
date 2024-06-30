class Solution {
public:
  vector<double> getCollisionTimes(vector<vector<int>>& c) {
    auto col_time = [&](int i, int j) { 
        return (double)(c[i][0] - c[j][0]) / (c[j][1] - c[i][1]); 
    };
    vector<double> res(c.size(), -1), s;
    for (int i = c.size() - 1; i >= 0; --i) {
        while (!s.empty() && (c[i][1] <= c[s.back()][1] || 
                              (s.size() > 1 && col_time(i, s.back()) >= res[s.back()])))
            s.pop_back();
        res[i] = s.empty() ? -1 : col_time(i, s.back());
        s.push_back(i);
    }
    return res;
}
};
