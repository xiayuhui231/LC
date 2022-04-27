class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n;
        while(left<right){
            int middle = left + ((right-left) >> 1);
                if(nums[middle] > target){
                    right = middle;
                }else if(nums[middle]<target){
                    left = middle + 1;
                }else{
                    return middle;
                }
        }
        return  right;
