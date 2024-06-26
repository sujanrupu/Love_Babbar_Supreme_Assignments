class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string a = strs[0], b = strs[n-1];
        string ans = "";
        for(int i = 0; i < min(a.length(), b.length()); i++) {
            if(a[i] == b[i])    ans.push_back(a[i]);
            else    return ans;
        }
        return ans;
    }
};
