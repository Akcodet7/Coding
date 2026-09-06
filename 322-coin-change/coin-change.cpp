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
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1,0));

        for(int j=1; j<=amount; j++) {
            if(j%coins[0]==0)
            dp[0][j] = j/coins[0];
            else dp[0][j] = INT_MAX;
        }
        for(int i=1; i<coins.size(); i++) {
            for(int j=1; j<=amount; j++) {
                int minn = INT_MAX;
                int a=0;
                while(coins[i]*a<=j) {
                    if(dp[i-1][j-coins[i]*a]<INT_MAX) minn = min(minn, a+dp[i-1][j - coins[i]*a]);
                    a++;
                }
                dp[i][j] = minn;
            }
        }
        if(dp[coins.size()-1][amount]==INT_MAX) return -1;
        return dp[coins.size()-1][amount];
            // if (f(0, coins, amount, dp)==INT_MAX) return -1;
            // return f(0, coins, amount, dp);
    }
};