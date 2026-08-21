class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        //bool color=true;
        vector<pair<int,int>> vis(graph.size(),{0,-1});
        for(int i=0; i<graph.size(); i++) {
            if(vis[i].first==1) continue;
            q.push(i);
            vis[i].first=1;
            vis[i].second=0;
            while(!q.empty()) {
                int node=q.front();
                q.pop();
                for(int i=0; i<graph[node].size(); i++) {
                    if(vis[vis[graph[node][i]].first==1].first==1 && vis[graph[node][i]].second==vis[node].second) return false;
                    if(vis[graph[node][i]].first==0) {
                        q.push(graph[node][i]);
                        vis[graph[node][i]].first=1;
                        vis[graph[node][i]].second=!vis[node].second;
                    }
                }
            }
        }
        return true;
    }
};