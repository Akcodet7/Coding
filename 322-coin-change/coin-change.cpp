class Solution {
public:

    int f(int ind, vector<int>&coins, int amount, vector<vector<int>>&dp) {
        if(ind==coins.size()) {
            if(amount==0) return 0;
            return INT_MAX;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int minn = INT_MAX;
        int cost=1;
        for(int i=0; ;i++) {
            cost = coins[ind]*i;
            if(cost>amount) break;
            if (f(ind+1, coins, amount-cost, dp)<INT_MAX) minn = min(minn, i+f(ind+1, coins, amount-cost, dp));
        }
        return dp[ind][amount] = minn;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1,-1));
        if (f(0, coins, amount, dp)==INT_MAX) return -1;
        return f(0, coins, amount, dp);
    }
};