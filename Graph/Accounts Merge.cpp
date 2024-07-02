class DisjointSet{
    
public:
    vector<int>rank, parent;

    DisjointSet (int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        
        // Everyone is initially their own parent, because independence!
        for(int i=0; i<=n; i++) parent[i]=i;
    }
    
    int findUltimateParent(int node){
        // The ultimate parent is like the final boss; we keep looking until we find it.
        if(node == parent[node]) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }
    
    void unionByRank(int node1, int node2){
        int parent1 = findUltimateParent(node1);
        int parent2 = findUltimateParent(node2);
        
        if(parent1 == parent2) return; // They're already in the same group, nothing to see here.
        else if(rank[parent1] < rank[parent2]){
            parent[parent1] = parent2; // Merge smaller group into the larger one.
        }
        else if(rank[parent2] < rank[parent1]){
            parent[parent2] = parent1; // Merge smaller group into the larger one.
        }
        else if(rank[parent1] == rank[parent2]){
            parent[parent2] = parent1; // Same rank, choose one and increase rank.
            rank[parent1]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> m;

        // Associate emails with their accounts.
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];

                if(m.find(mail) == m.end()){
                    m[mail] = i;
                }
                else{
                    ds.unionByRank(m[mail], i);
                }
            }
        }

        // Collect emails by their ultimate parent.
        vector<string> users_acc[n];

        for(auto it : m){
            string mail = it.first;
            int node = ds.findUltimateParent(it.second);
            users_acc[node].push_back(mail);
        }

        vector<vector<string>> merged_acc;

        // Prepare the final merged account list.
        for(int i = 0; i < n; i++){
            if(users_acc[i].size() == 0) continue;

            sort(users_acc[i].begin(), users_acc[i].end());

            vector<string> merge;
            merge.push_back(accounts[i][0]);

            for(auto it : users_acc[i]){
                merge.push_back(it);
            }

            merged_acc.push_back(merge);
        }

        return merged_acc;
    }
};
