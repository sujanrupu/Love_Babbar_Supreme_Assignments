class Solution {
public:
    void dfs(int src, unordered_map<int, bool>& vis, vector<int>adj[]) {
        vis[src] = 1;
        for(auto it : adj[src]) {
            if(!vis[it])
                dfs(it, vis, adj);
        }
    }

    int makeConnected(int n, vector<vector<int>>& cnt) {
        int len = cnt.size();
        if(len < n-1)   return -1;
        vector<int>adj[n];
        for(auto it : cnt) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        unordered_map<int, bool>vis;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                ans ++;
                dfs(i, vis, adj);
            }
        }
        return ans-1;
    }
};
