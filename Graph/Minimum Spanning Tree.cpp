class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, 0});
        int ans = 0;
        vector<int>vis(V, 0);
        while(!pq.empty()) {
            auto top = pq.top();    pq.pop();
            int weight = top.first, node = top.second;
            if(vis[node] == 1)  continue;
            ans += weight;
            vis[node] = 1;
            for(auto it : adj[node]) {
                int adjNode = it[0], weight = it[1];
                pq.push({weight, adjNode});
            }
        }
        return ans;
    }
};
