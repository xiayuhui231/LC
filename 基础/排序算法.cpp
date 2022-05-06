class Solution {
public:

    vector<int> sortArray(vector<int>& nums) {
        Shell_Sort(nums);
        return nums;

            
    }
        void Shell_Sort(vector<int>& nums){
        int n = nums.size();
        int i,j,gap;
        for(gap = n/2;gap>0;gap /=2){
            for(i=0;i<gap;i++){
                for(j=i+gap;j<n;j+=gap){
                    if(nums[j] < nums[j-gap]){
                        int tmp = nums[j];
                        int k = j-gap;
                        while(k >= 0 && nums[k] > tmp){
                            nums[k+gap] = nums[k];
                            k -= gap;
                        }
                        nums[k+gap] = tmp;
                    }
                }
            }
        }
    }
};