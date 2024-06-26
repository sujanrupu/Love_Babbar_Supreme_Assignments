class Solution
{
  public:
    bool check(int arr[], int n, int m, int ans) {
        int count = 1, totalPage = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] > ans)    return false;
            else if(totalPage + arr[i] > ans) {
                count++;
                totalPage = arr[i];
                if(count > m)   return false;
            }
            else    totalPage += arr[i];
        }
        return true;
    }
  
    long long minTime(int arr[], int n, int m)
    {
        long long start = 0, end = 0, ans = -1;
        for(int i = 0; i < n; i++)
            end += arr[i];
        while(start <= end) {
            long long mid = start + (end - start)/2;
            if(check(arr, n, m, mid)) {
                ans = mid;
                end = mid - 1;
            }
            else    start = mid + 1;
        }
        return ans;
    }
};
