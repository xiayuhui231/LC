class Solution {
public:
vector<int> v;
    unordered_map<int, int> m; //保存用过的列
    int ans = 0;
    void dfs(int row, int n) {
        if (row > n) {
            ans++;
            return;
        }

        for (int j = 1; j <= n; j++) { //row行的列
            if (m.find(j) == m.end()) { 
                int condition = 1;
                for (int k = 1; k < row; k++) { 
                    if (k - v[k] == row - j || k + v[k] == row + j) { //验证对角线是否满足条件
                        condition = 0;
                        break;
                    }
                }
                if (condition == 1) {
                    v[row] = j;
                    m[j]++;
                    dfs(row + 1, n);
                    v[row] = 0; // 回溯
                    m.erase(j); // 删除key为j的map?
                }
            }
        }
    }

    int totalNQueens(int n) {
        v.resize(n + 5);
        dfs(1, n);
        return ans;
    }
};