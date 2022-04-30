vector<int> colors;
    vector<vector<int>> G;
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        G=vector<vector<int>>(n);
        for(auto& d:dislikes)
        {
            G[d[0]-1].push_back(d[1]-1);
            G[d[1]-1].push_back(d[0]-1);
        }
        
        colors=vector<int>(n,0);
        
        for(int i=0;i<colors.size();i++)
        {
            if(colors[i]==0 && !dfs(i,1))
                return false;
        }
        return true;
    }
    
    bool dfs(int cur, int color)
    {
        colors[cur]=color;
        for(int next:G[cur])
        {
            if(colors[next]==color)
                return false;
            if(colors[next]==0 && !dfs(next,-color))
                return false;
        }
        return true;
    }