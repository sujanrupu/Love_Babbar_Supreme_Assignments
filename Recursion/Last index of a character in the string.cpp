class Solution{
    public:
    int LastIndex(string s, char p){
        for(int i = s.length()-1; i >= 0; i--) {
            if(s[i] == p)   return i;
        }
        return -1;
    }
};
