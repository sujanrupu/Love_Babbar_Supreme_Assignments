class Solution {
  public:
    long long int inversionCount(long long arr[], int n) {
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(arr[j] < arr[i]) ans++;
            }
        }
        return ans;
    }
};
