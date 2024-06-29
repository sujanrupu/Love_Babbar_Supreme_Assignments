class Solution 
{
    public:
    int celebrity(vector<vector<int> >& M, int n) 
    {
        vector<int>row;
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(M[i][j] == 0)    count++;
            }
            if(count == n)  row.push_back(i);
        }
        if(row.size() != 1)  return -1;
        int celeb = row[0];
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(M[i][celeb] == 1)    count++;
        }
        if(count == n-1)    return celeb;
        else    return -1;
    }
