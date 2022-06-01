class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), sum = 0;
        for(int num : nums) sum += num;
        if(sum+target < 0) return 0;
        if((sum + target) %2) return 0;
        int m = (sum + target) /2;
        vector<int>dp(m+1,0);
        dp[0] = 1;
        for(int num : nums){
            for(int i = m; i>= num; i--){
                dp[i] += dp[i-num];
            }
        }
        return dp[m];
    }
};