class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n + 1 , 0);
        vector<int> outDegree(n + 1 , 0);

        for(const auto pairs : trust){
            inDegree[pairs[1]] += 1;
            outDegree[pairs[0]] += 1;
        }
        
        for(int i = 1; i < inDegree.size() ; ++i){
            if(inDegree[i] == n - 1 and outDegree[i] == 0)      return i;
        }
        return -1;
    }
};