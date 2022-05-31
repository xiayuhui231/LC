class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size(), sum = 0;
        for (auto &x : nums)
            sum += x;
        if (sum % 2 == 1)
            return false;
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (auto &x : nums)
        {
            for (int i = target; i >= x; i--)
                dp[i] |= dp[i - x];
        }
        return dp[target];
    }
};