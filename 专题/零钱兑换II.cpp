class Solution1 {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount+1];
        memset(dp, 0, sizeof(dp)); //初始化数组为0
        dp[0] = 1;
        for (int j = 1; j <= amount; j++){ //枚举金额
            for (int coin : coins){ //枚举硬币
                if (j < coin) continue; // coin不能大于amount
                dp[j] += dp[j-coin];
            }
        }
        return dp[amount];
    }
};