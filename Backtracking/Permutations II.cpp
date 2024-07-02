class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        string str = "";
        for(int i = 0; i < nums.size(); i++)
            str.push_back((char)nums[i]);
        vector<string>arr;
        arr.push_back(str);
        string s = str;
        while(next_permutation(begin(str), end(str))) {
            if(s == str)    break;
            arr.push_back(str);
        }
        vector<vector<int>>ans;
        for(int i = 0; i < arr.size(); i++) {
            vector<int>temp;
            for(int j = 0; j < arr[i].length(); j++)
                temp.push_back((int)arr[i][j]);
            ans.push_back(temp);
        }
        return ans;
    }
};
