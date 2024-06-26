class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int i = 0, j = 0, k = 0;
            vector<int>ans;
            set<int>s;
            while(i<n1 && j<n2 && k<n3) {
                if(A[i] == B[j] && B[j] == C[k]) {
                    s.insert(A[i]);
                    i++;    j++;    k++;
                }
                else if(A[i] < B[j])    i++;
                else if(B[j] < C[k])    j++;
                else    k++;
            }
            for(auto it : s)
                ans.push_back(it);
            return ans;
        }

};
