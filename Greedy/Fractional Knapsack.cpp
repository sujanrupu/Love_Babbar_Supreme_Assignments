class Solution {
  public:
    static bool cmp(pair<Item, double>& a, pair<Item, double>& b) {
        return a.second > b.second;
    }
    
    double fractionalKnapsack(int w, Item arr[], int n) {
        vector<pair<Item, double>>v;
        for(int i = 0; i < n; i++) {
            double perUnitValue = (1.0 * arr[i].value)/arr[i].weight;
            v.push_back({arr[i], perUnitValue});
        }
        sort(v.begin(), v.end(), cmp);
        double totalValue = 0;
        for(int i = 0; i < v.size(); i++) {
            if(v[i].first.weight > w) {
                totalValue += (w * v[i].second);
                w = 0;
            }
            else {
                w -= v[i].first.weight;
                totalValue += v[i].first.value;
            }
        }
        return totalValue;
    }
};
