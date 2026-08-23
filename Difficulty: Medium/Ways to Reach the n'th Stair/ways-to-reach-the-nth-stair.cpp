class Solution {
  public:
    
    int f(vector<int>&dp, int n) {
        if(n<=2) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n] =  f(dp, n-1)+f(dp, n-2);
    }
  
    int countWays(int n) {
        vector<int> dp(n+1, -1);
        return f(dp,n);
    }
};
