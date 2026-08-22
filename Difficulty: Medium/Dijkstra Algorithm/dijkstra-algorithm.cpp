class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][2], edges[i][1]});
            adj[edges[i][1]].push_back({edges[i][2], edges[i][0]});
        }
        //priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        set<pair<int,int>> s;
        vector<int> dist(V,INT_MAX);
        dist[src]=0;
        s.insert({0,src});
        while(!s.empty()) {
            auto it=*(s.begin());
            int d=it.first;
            int node=it.second;
            s.erase(it);
            for(int i=0; i<adj[node].size(); i++) {
                int weight=adj[node][i].first;
                int neighbor=adj[node][i].second;
                if(dist[neighbor] > (weight+dist[node])) {
                    if(dist[neighbor]!=INT_MAX) {
                        s.erase({dist[neighbor],neighbor});
                    }
                    dist[neighbor] = weight+dist[node];
                    s.insert({dist[neighbor], neighbor});
                }
            }
        }
        return dist;
    }
};