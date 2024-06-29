class Solution
{
  public:
    int findPairs(long long a[], long long n)
    {
        if(n <= 3)  return 0;
        vector<long long>arr;
        for(int i = 0; i < n; i++)
            arr.push_back(a[i]);
        vector<long long>sum;
        for(long long i = 0; i < arr.size(); i++) {
            for(long long j = i + 1; j < arr.size(); j++) 
                sum.push_back(arr[i] + arr[j]);
        }
        sort(sum.begin(), sum.end());
        for(long long i = 0; i < sum.size()-1; i++) {
            if(sum[i] == sum[i+1])  return 1;
        }
        return 0;
    }
};
