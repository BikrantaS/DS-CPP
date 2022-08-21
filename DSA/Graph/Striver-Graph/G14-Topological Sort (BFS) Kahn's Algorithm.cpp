https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
//Topological Sort (BFS) kahn's Algorithm
//TC:N+E SC:N+N

vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>  indegrees(V,0);
	    vector<int> ans;
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    {
	        for(int x:adj[i])
	        indegrees[x]++;
	    }
	    
	    for(int i=0;i<V;i++)
	    {
	        if(indegrees[i]==0)
	        q.push(i);
	    }
	    
	    
	    while(!q.empty())
	    {
	        int node=q.front();q.pop();
	        ans.push_back(node);
	        for(int x:adj[node])
	        {
	            indegrees[x]--;
	            if(indegrees[x]==0)q.push(x);
	        }
	    }
	    return ans;
	}