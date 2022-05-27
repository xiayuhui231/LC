class Solution {
public:
    using P = pair<int,int>;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> res;
        auto comp = [&](const P& a, const P& b){
            if(a.first != b.first) return a.first > b.first;
            else return a.second > b.second;
        };
        priority_queue<P,vector<P>,decltype(comp)> pq(comp);
        
        int cnt = 0, n = tasks.size(), idx = 0, i = 0;
        long long t = 1;
        for(auto& vec: tasks){
            vec.push_back(i++);
        }
        sort(tasks.begin(),tasks.end());
        while(cnt < n){
            bool exec = false;
            while(idx < n){
                if(tasks[idx][0] <= t){
                    exec = true;
                    pq.push(P(tasks[idx][1],tasks[idx][2]));
                    ++idx;
                }
                else{
                    if(!exec && pq.empty()){
                        t = tasks[idx][0];
                    }
                    break;
                }
            }
            
            if(pq.empty()) continue;
            auto curr = pq.top();
            pq.pop();
            res.push_back(curr.second);
            t += curr.first;
            ++cnt;
        }
        
        return res;

    }
};