class Solution {
  public:
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> ind(V,0);
        vector<vector<int>> adj(V);
        queue<int> q;
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            ind[edges[i][1]]++;
        }
        for(int i=0; i<ind.size(); i++) {
            if(ind[i]==0) q.push(i);
        }
        int count=0;
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            count++;
            for(int i=0; i<adj[node].size(); i++) {
                ind[adj[node][i]]--;
                if(ind[adj[node][i]]==0) q.push(adj[node][i]);
            }
        }
        if(count<V) return true;
        return false;
        
    }
};