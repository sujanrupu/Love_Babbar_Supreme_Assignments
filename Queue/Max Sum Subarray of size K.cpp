class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long ans = 0;
        for(int i = 0; i <= N-K; i++) {
            long sum = 0;
            for(int j = i; j < (i+K); j++)
                sum += Arr[j];
            ans = max(ans, sum);
        }
        return ans;
    }
};
