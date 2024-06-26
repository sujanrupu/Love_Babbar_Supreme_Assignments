class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        vector<int>a, b;
        for(int i = 0; i < n; i++) {
            if(arr[i] >= 0)  a.push_back(arr[i]);
            else    b.push_back(arr[i]);
        }
        for(int i = 0; i < a.size(); i++)   arr[i] = a[i];
        for(int i = 0; i < b.size(); i++)   arr[i+a.size()] = b[i];
    }
};
