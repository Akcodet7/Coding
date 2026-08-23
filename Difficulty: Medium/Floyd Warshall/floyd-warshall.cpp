class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        for(int i=0; i<dist.size(); i++) {
            for(int j=0; j<dist[0].size(); j++) {
                if(dist[j][i]==1e8) continue;
                for(int k=0; k<dist[j].size(); k++) {
                    if(dist[i][k]==1e8) continue;
                    if(k==i || k==j) continue;
                    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
                }
            }
        }
    }
};