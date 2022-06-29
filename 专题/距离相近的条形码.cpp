class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
        priority_queue<pair<int, int>> q;
        unordered_map<int,int> mp;
        for(auto x: b){
            mp[x]++;
        }
        for(const auto &[k, v]: mp) {
            q.push({v, k});
        }
        vector<int> res;

        while(q.size()) {
            auto [v, k] = q.top(); q.pop();
            if(res.empty() || res.back() != k) {
                res.push_back(k);
                if(--v) q.push({v, k});
            }else{
                if(q.size() < 1) return res;
                auto [y, x] = q.top(); q.pop();
                res.push_back(x);
                if(--y) q.push({y, x});
                q.push({v, k});
            }
        }
        return res;
    }
};