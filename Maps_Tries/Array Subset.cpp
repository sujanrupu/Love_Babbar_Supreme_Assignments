string isSubset(int a1[], int a2[], int n, int m) {
    vector<int>vis(n, 0);
    for(int i = 0; i < m; i++) {
        int count = 0, j = 0;
        while(j<n && count == 0) {
            if(a2[i] == a1[j] && !vis[j])  {
                count++;
                vis[j] = 1;
            }
            j++;
        }
        if(count == 0)  return "No";
    }
    return "Yes";
}
