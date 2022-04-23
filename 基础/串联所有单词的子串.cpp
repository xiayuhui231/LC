class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty()) return {};
        int n = words.size(), m = words[0].size(),j=0;
        if(s.size() < m*n) return {};
        vector<int> res;
        unordered_map<string,int>mp,tmp;
        for(auto str: words){
            mp[str]++;
        }
        string str = "";
        for(int i = 0; i+m*n<= s.size();i++){
            for( j = i;j<i+m*n;j+=m){
                str =  s.substr(j,m);
                if(mp.find(str) == mp.end()) break;
                tmp[str]++;
            }
            if(j == i+m*n && tmp == mp) res.push_back(i);
            tmp.clear();
        }
        return res;

    }
};