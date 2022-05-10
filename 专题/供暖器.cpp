bool is_enough(vector<int>& nums, int diameter) {
    int count = 0;
    for (int i = 0; i < nums.size();) {
        int j = i + 1;
        // cout<<"i,j"<<i<<" "<<j<<endl;
        for (; j < nums.size(); j++) {
            if (nums[i] + diameter < nums[j]) {
                break;
            }
        }
        count++;
        i = j;
        // cout<<"count="<<count<<endl;
        if (count > 3) return false;
    }
    return true;
}

double solve(vector<int>& nums) {
    if (nums.size() <= 1) return 0;
    sort(nums.begin(), nums.end());
    int left = 0;
    int diff = nums[0] - left;
    int right = nums.back() - diff;
    int diameter = 0;

    while (left < right) {
        diameter = (right + left) >> 1;
        if (is_enough(nums, diameter)) {
            right = diameter;
            // cout<<"True right="<<right<<endl;
        } else {
            left = diameter + 1;
            // cout<<"False left="<<left<<endl;
        }
    }
    double ret = ((double)right) / 2;
    return ret;
}