class Solution {
  public:
  
    int f(vector<int> &dp, int n, vector<int> &heights) {
        if(n<=2) return abs(heights[n]-heights[0]);
        if(dp[n]!=-1) return dp[n];
        int one = f(dp, n-1, heights) + abs(heights[n]-heights[n-1]);
        int two = f(dp, n-2, heights) + abs(heights[n]-heights[n-2]);
        return dp[n] = min(one,two);
    }
    int curri=0, ts, os;
    int minCost(vector<int>& heights) {
        int prev = 0;
        int prev2 = 0;
        for(int i=1; i<heights.size(); i++) {
            os = prev + abs(heights[i]-heights[i-1]);
            ts = INT_MAX;
            if(i>1) ts = prev2 +abs(heights[i]-heights[i-2]);
            curri = min(os, ts);
            prev2 = prev;
            prev = curri;
        }
        return curri;
    }
};