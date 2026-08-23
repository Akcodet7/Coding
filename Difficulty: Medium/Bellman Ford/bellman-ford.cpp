class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V,1e8);
        dist[src] = 0;
        for(int i=1; i<V; i++) {
            for(int j=0; j<edges.size(); j++) {
                if(dist[edges[j][0]]==1e8) continue;
                if(dist[edges[j][1]] > dist[edges[j][0]] + edges[j][2]) {
                    dist[edges[j][1]] = dist[edges[j][0]] + edges[j][2];
                }
            }
        }
        bool flag=false;
        for(int j=0; j<edges.size(); j++) {
                if(dist[edges[j][0]]==1e8) continue;
                if(dist[edges[j][1]] > dist[edges[j][0]] + edges[j][2]) {
                    dist[edges[j][1]] = dist[edges[j][0]] + edges[j][2];
                    flag=true;
                }
        }
        if(flag) return {-1};
        return dist;
    }
};
