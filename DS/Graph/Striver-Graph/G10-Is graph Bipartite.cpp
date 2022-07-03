

https://leetcode.com/problems/is-graph-bipartite/
//Is Graph Bipartite?

bool dfsBipartite(int source,vector<vector<int>>& graph,vector<int>& vis)
    {
        if(vis[source]==-1)
        vis[source]=1;
        for(int x:graph[source])
        {
            if(vis[x]==-1)
            {
                vis[x]=1-vis[source];
                if(dfsBipartite(x,graph,vis)==false)
                    return false;
            }
            else if(vis[x]==vis[source]) return false;
            
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        //DFS
        int n=graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                if(dfsBipartite(i,graph,vis)==false)
                    return false;
            }
                
        }
        return true;
            
    }


////////////////////////////////////////////////////////////////////////////////

bool bfsBipartite(int source,vector<vector<int>>& graph,vector<int>& vis)
    {
        queue<int> q;
	    q.push(source);
	    vis[0]=1;
        while(!q.empty())
        {
            int node=q.front();q.pop();
            for(auto x:graph[node])
            {
                if(vis[x]==-1)
	            {
	                q.push(x);
	                vis[x]=1-vis[node];
	            }
                else if(vis[x]==vis[node])return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        //BFS
        int n=graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                if(bfsBipartite(i,graph,vis)==false)
                    return false;
            }
                
        }
        return true;
            
    }