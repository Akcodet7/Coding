class Solution {
public:

    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>>&dp) {
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = grid[i][j]+min(f(i-1,j,grid,dp), f(i, j-1, grid,dp));
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),-1));
        return f(grid.size()-1, grid[0].size()-1, grid, dp);
    }
};