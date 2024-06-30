class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tp) {
        int n = tp.size();
        vector<int>ans;
        for(int i = 0; i < n; i++) {
            int j = i + 1, count = 0;
            while(j < n && count == 0) {
                if(tp[j] > tp[i])   count++;
                j++;
            }
            if(count == 0)  ans.push_back(0);
            else    ans.push_back(j - 1 - i);
        }
        return ans;
    }
};
