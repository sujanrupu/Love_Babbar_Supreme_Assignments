class Solution {
public:
    bool isPal(string &s) {
        int start = 0, end = s.length()-1;
        while(start < end) {
            if(s[start]!=s[end])    return false;
            start++;    end--;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& word) {
        vector<vector<int>>ans;
        for(int i = 0; i < word.size(); i++) {
            for(int j = 0; j < word.size(); j++) {
                if(j != i)  {
                    string str = word[i] + word[j];
                    if(isPal(str))  {
                        vector<int>arr;
                        arr.push_back(i);
                        arr.push_back(j);
                        ans.push_back(arr);
                    }
                }
            }
        }
        return ans;
    }
};
