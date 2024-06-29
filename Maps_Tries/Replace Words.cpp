class Solution {
public:
    string replaceWords(vector<string>& dict, string sent) {
        sort(dict.begin(), dict.end());
        vector<string>arr;
        string temp = "";
        for(int i = 0; i < sent.length(); i++) {
            if(sent[i] ==' ') {
                arr.push_back(temp);
                temp = "";
            }
            else
                temp.push_back(sent[i]);
        }
        arr.push_back(temp);
        for(int i = 0; i < arr.size(); i++) {
            int j = 0, count = 0;
            while(j < dict.size() && count == 0) {
                int ind = arr[i].find(dict[j]);
                if(ind == 0) {
                    arr[i] = dict[j];
                    count++;
                }
                j++;
            }
        }
        string ans ="";
        for(int i = 0; i < arr.size()-1; i++) {
            ans += arr[i];
            ans += " ";
        }
        ans += arr[arr.size()-1];
        return ans;
    }
};
