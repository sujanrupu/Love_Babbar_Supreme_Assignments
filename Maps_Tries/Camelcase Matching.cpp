class Solution {
public:
    bool check(string a, string b) {
        int i = 0, j = 0;
        while(i < a.size()) {
            if(j<b.size() && a[i]==b[j]) 
                j++;
            else if(a[i]>='A' && a[i]<='Z')
                return false;
            i++;
        }
        return j == b.size();
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>res;
        for(int i=0; i<queries.size(); i++) {
            bool ans = check(queries[i], pattern);
            res.push_back(ans);
        }
        return res;
    }
};
