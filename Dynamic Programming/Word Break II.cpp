class Solution {
public:
    vector<string> solve(string &s, unordered_map<string, bool>& mp, int index) {
        if(index >= s.length()) return {""};
        vector<string>ans;
        string word = "";
        for(int i = index; i < s.length(); i++) {
            word += s[i];
            if(mp.find(word) == mp.end())   continue;
            auto right = solve(s, mp, i+1);
            for(auto it : right) {
                string end = "";
                if(it.size() > 0)   end = " " + it;
                ans.push_back(word + end);
            }
        }
        return ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool>mp;
        for(auto it : wordDict) mp[it] = 1;
        return solve(s, mp, 0);
    }
};
