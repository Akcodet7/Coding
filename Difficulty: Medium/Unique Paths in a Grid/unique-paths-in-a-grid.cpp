class Solution {
  public:
    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>>&dp) {
        if(i==grid.size()-1 && j==grid[0].size()) return 1;
        if(i>=grid.size() || j>=grid[0].size()) return 0;
        if(grid[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = f(i+1, j, grid, dp)+f(i,j+1,grid, dp);
    }
  
    int uniquePaths(vector<vector<int>> &grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),-1));
        return f(0,0,grid,dp);
    }
};