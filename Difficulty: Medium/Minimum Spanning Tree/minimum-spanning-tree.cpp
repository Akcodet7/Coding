class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<int> vis(V,0);
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][2], edges[i][1]});
            adj[edges[i][1]].push_back({edges[i][2], edges[i][0]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(vis[node]) continue;
            vis[node]=1;
            sum += dist;
            for(int i=0; i<adj[node].size(); i++) {
                int nbr = adj[node][i].second;
                int wt = adj[node][i].first;
                if(!vis[nbr]) pq.push({wt,nbr});
            }
        }
        return sum;
    }
};