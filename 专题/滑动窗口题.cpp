int solve(vector<int>& nums, int target) {
    // 双指针
    int N = nums.size();
    int newTarget = accumulate(nums.begin(), nums.end(), 0) - target;
    if (newTarget == 0) return N;
    int curSum = 0;
    int maxLen = 0;
    int left = 0;  // left: 滑动窗口左边界, i: 滑动窗口右边界right
    for (int i = 0; i < N; i++)
    {
        curSum += nums[i];
        while (curSum >= newTarget && i >= left) // 寻找一个新的和为newTarget的滑动窗口区间
        {
            if (curSum == newTarget) // 当找到的新的和为newTarget的滑动窗口区间更长时, 更新其长度
                maxLen = max(maxLen, i - left + 1);

            curSum -= nums[left]; // 扔掉滑动窗口最左侧的数
            left++;
        }
    }
    return maxLen == 0 ? -1 : N - maxLen;
}