class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp (amount + 1, amount + 1);
        dp[0] = 0;
        
        for(int i = 0; i < coins.size(); i++) {
            for(int k = coins[i]; k <= amount; k++) {
                dp[k] = min(dp[k], dp[k - coins[i]] + 1);
            }
        }
        
        if(dp[amount] == amount + 1) return -1;
        return dp[amount];
    }
};