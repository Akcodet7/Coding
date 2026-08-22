class Solution {
public:

    bool dfs(vector<vector<int>> &graph, vector<int> &vis, int node, int color) {
        vis[node]=color;
        for(int i=0; i<graph[node].size(); i++) {
            if(vis[graph[node][i]]==vis[node]) return false;
            if(vis[graph[node][i]]==-1 && !dfs(graph,vis,graph[node][i],!color)) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),-1);
        for(int i=0; i<graph.size(); i++) {
            if(vis[i]==-1 && !dfs(graph,vis,i,0)) {
                return false;
            } 
        }
        return true;
    }
};