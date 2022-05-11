class Solution {
public:
    bool possible(vector<int>& nums,int k,int differ){
        //双指针判断
        int i=0,j=0;
        long count=0;
        while(i<nums.size() || j<nums.size()){
            while(j<nums.size() && nums[j]-nums[i]<=differ){
                j++;
            }
            count+=j-i-1;
            i++;
        }
        return count>=k;
    }
    //二分法，确定上下界，能力检测函数
    int smallestDistancePair(vector<int>& nums, int k) {
        //二分法，先排序
        sort(nums.begin(),nums.end());
        int left=0;
        int right=nums[nums.size()-1]-nums[0];
        while(left<right){
            int mid=left+(right-left)/2;
            if(possible(nums,k,mid)){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};