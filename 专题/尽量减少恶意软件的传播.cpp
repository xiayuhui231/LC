class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        //初始化并查集
        const int gsize = graph.size();
        vector<int> parents(gsize);
        for (int i = 0; i < gsize; ++i) {
            parents[i] = i;
        }
        vector<int> rank(gsize, 1);//非标准意义rank，用来统计联通分量节点数
        unordered_map<int, int> virus;//每个parent下的患病数量
        //开始union,遍历下三角矩阵
        for (int i = 1; i < gsize; ++i) {
            for (int j = 0; j < i; ++j) {
                if (graph[i][j] == 1) {
                    int lhs = i, rhs = j;
                    while (parents[lhs] != lhs) lhs = parents[lhs];
                    parents[i] = lhs;//路径压缩
                    while (parents[rhs] != rhs) rhs = parents[rhs];
                    parents[j] = rhs;
                    if (lhs == rhs) continue;
                    if (rank[lhs] < rank[rhs]) {
                        rank[lhs] += rank[rhs];//按秩合并
                        parents[rhs] = lhs;
                    } else {
                        rank[rhs] += rank[lhs];
                        parents[lhs] = rhs;
                    }
                }
            }
        }
        for (int i : initial) {
            while (i != parents[i]) i = parents[i];
            ++virus[parents[i]];
        }
        //剔除感染数不为1的联通分量 以及非最大的联通分量
        int M = -1, pos = 0;
        for (auto iter = virus.begin(); iter != virus.end();) {
            if (iter->second != 1) {
                auto tmp = iter;
                ++iter;
                virus.erase(tmp);
            } else {
                M = (rank[iter->first] > M)? rank[iter->first] : M;
                ++iter;
            }
        }
        for (auto iter = virus.begin(); iter != virus.end();) {
            if (rank[iter->first] < M) {
                auto tmp = iter;
                ++iter;
                virus.erase(tmp);
            } else {
                ++iter;
            }
        }
        //没有符合要求的节点，返回索引最小值
        if (M == -1) {
            int min = INT32_MAX;
            for (int i : initial) {
                if (i < min) min = i;
            }
            return min;
        };
        //返回感染数为1的联通分量的感染者索引最小值
        int min = INT32_MAX;
        for (int i : initial) {
            int j = i;
            while (j != parents[j]) j = parents[j];
            if (virus.find(j) != virus.end()) min = (i < min)? i : min;
        }
        return min;
    }
};