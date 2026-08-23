class Solution {
  public:
  
    int f(vector<int> &dp, int n, vector<int> &heights) {
        if(n<=2) return abs(heights[n]-heights[0]);
        if(dp[n]!=-1) return dp[n];
        int one = f(dp, n-1, heights) + abs(heights[n]-heights[n-1]);
        int two = f(dp, n-2, heights) + abs(heights[n]-heights[n-2]);
        return dp[n] = min(one,two);
    }
  
    int minCost(vector<int>& height) {
        vector<int> dp(height.size(), -1);
        return f(dp, height.size()-1, height);
    }
};