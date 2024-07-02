class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<pair<string, int>>q;
        q.push({beginWord, 0});
        st.erase(beginWord);
        while(!q.empty()) {
            string fword = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(fword == endWord)    return (steps+1);
            for(int i = 0; i < fword.length(); i++) {
                char original = fword[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    fword[i] = ch;
                    if(st.find(fword)!=st.end()) {
                        q.push({fword, steps+1});
                        st.erase(fword);
                    }
                }
                fword[i] = original;
            }
        }
        return 0;
    }
};
