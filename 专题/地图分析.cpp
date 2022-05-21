class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
using P = pair<int, int>;
        int n = grid.size();
        queue<P> q;
        vector<vector<int>> dis(grid);
        // 把所有陆地加进队列，作为源节点
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    dis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        // 判断是否都是海洋或者陆地
        if (q.size() == n * n || q.empty()) return -1;
        int res = 0;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int tx = x + dx[i], ty = y + dy[i];
                    if (tx >= 0 && tx < n && ty >= 0 && ty < n && !grid[tx][ty])
                    {
                        grid[tx][ty] = 1;
                        q.push({tx, ty});
                        // 记录从源出发的距离
                        dis[tx][ty] = dis[x][y] + 1;
                        // 记录最远距离
                        res = max(res, dis[tx][ty]);
                    }
                }
            }
        }
        return res;
    }
};