class Solution
{
public:
    double knightProbability(int n, int k, int row, int column)
    {
        double dp[25][25][101] = {0};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j][0] = 1;

        int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        for (int step = 1; step <= k; step++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int u = 0; u < 8; u++)
                    {
                        int x = i + dx[u], y = j + dy[u];
                        if (x >= 0 && x < n && y >= 0 && y < n)
                        {
                            dp[i][j][step] += dp[x][y][step - 1] / 8;
                        }
                    }
                }
            }
        }
        return dp[row][column][k];
    }
};