int find(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (nums[mid] <= target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

int solve(vector<int>& nums) {
    int res = 0;
    vector<int> sortedNums;
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        int left = find(sortedNums, num * 3);
        res += i - left;
        int idx = find(sortedNums, num);
        sortedNums.insert(sortedNums.begin() + idx, num);
    }
    return res;
}