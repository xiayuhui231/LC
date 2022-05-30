class Solution {
public:
    int maxChoosableInteger;
    vector<int> dp;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
            return false;
        this->maxChoosableInteger = maxChoosableInteger;
        int state = (1 << maxChoosableInteger)-1;
        dp.resize(state+1,-1);
        return dfs(state, desiredTotal);
    }
    bool dfs(int state, int desiredTotal) {
        if(dp[state]!=-1) return dp[state]==1?true:false;
        for (int i = maxChoosableInteger; i >= 1; i--) {
            if (!(state & (1 << (i-1)))) continue;
            else if (desiredTotal - i <= 0 || dfs(state & (~(1 << (i - 1))), desiredTotal - i) == false) {
                dp[state]=1;
                return true;
            }
        }
        dp[state]=0;
        return false;
    }

};