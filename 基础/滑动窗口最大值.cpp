class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  vector<int> res;
        deque<int> a;
        for(int i=0;i<nums.size();i++){
            while(!a.empty()&&nums[a.back()]<=nums[i])
                a.pop_back();
            if(!a.empty()&&a.front()==i-k)
                a.pop_front();
            a.push_back(i);
            if(i>=k-1)
                res.push_back(nums[a.front()]);
        }
        return res;
    }
};