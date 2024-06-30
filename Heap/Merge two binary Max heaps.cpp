class Solution{
    public:
    void heapify(vector<int>& v, int i, int n) {
        while(true) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            int swapInd = i;
            if(left<n && v[left]>v[i])
                swapInd = left;
            if(right<n && v[right]>v[swapInd])
                swapInd = right;
            if(i == swapInd)    break;
            swap(v[i], v[swapInd]);
            i = swapInd;
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int>c(a.begin(), a.end());
        c.insert(c.end(), b.begin(), b.end());
        for(int i = c.size()/2; i >= 0; i--)     
            heapify(c, i, c.size());
        return c;
    }
};
