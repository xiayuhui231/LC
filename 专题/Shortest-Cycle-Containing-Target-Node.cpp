int solve(vector<vector<int>>& graph, int target) 
{
    queue<int> q;
    vector<bool> visited(graph.size(), false);
    for (int &v : graph[target]) q.push(v);
    int res = 0;
    while (!q.empty()) 
    {
        int sz = q.size();
        res++;
        for (int i = 0; i < sz; i++) 
        {
            int v = q.front();
            q.pop();
            visited[v] = true;
            if (v == target) return res;
            for (int &u : graph[v]) 
            {
                if (!visited[u]) q.push(u);
            }
        }
    }
    return -1;
}