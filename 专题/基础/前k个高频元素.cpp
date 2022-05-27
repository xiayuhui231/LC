class Solution {
public:
    // 小顶堆
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(auto x:nums) map[x]++;
        
        priority_queue<pair<int,int>, vector<pair<int, int>>, mycomparison> pri_que;

        for(unordered_map<int,int>::iterator it = map.begin(); it != map.end(); it++){
            pri_que.push(*it);
            if(pri_que.size() > k){
                pri_que.pop();
            }
        }
        vector<int>res(k);
        for(int i = k-1;i>=0;i--){
            res[i] = pri_que.top().first;
            pri_que.pop();
        }
        return res;
    }
};