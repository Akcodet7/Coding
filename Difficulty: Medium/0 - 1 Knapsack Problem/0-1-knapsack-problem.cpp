class Solution {
  public:
  
    int f(int i, int W, vector<int>&val, vector<int>&wt, vector<vector<int>>& dp) {
        if(i==val.size()) return 0;
        if(dp[i][W]!=-1) return dp[i][W];
        int maxx=INT_MIN;
        if(wt[i]<=W) maxx = val[i] + f(i+1, W-wt[i], val, wt, dp);
        maxx = max(maxx, f(i+1, W, val, wt,dp));
        return dp[i][W] = maxx;
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<vector<int>> dp(val.size(), vector<int> (W+1,-1));
        return f(0,W,val,wt,dp);
    }
};