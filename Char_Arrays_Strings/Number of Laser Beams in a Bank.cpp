class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>arr;
        for(int i = 0; i < bank.size(); i++) {
            int count = 0;
            for(int j = 0; j < bank[i].length(); j++) {
                if(bank[i][j] == '1')   count++;
            }
            if(count >= 1)  arr.push_back(count);
        }
        if(arr.size() <= 1) return 0;
        int ans = 0;
        for(int i = 0; i < arr.size()-1; i++) 
            ans += (arr[i] * arr[i+1]);
        return ans;
    }
};
