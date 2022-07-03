https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
//Detect cycle in a directed graph using kahn's Algorithm
//TC:N+E SC:N+N

//BFS Kahns Algorithm
    bool isCyclic(int V, vector<int> adj[]) 
    {
        // code here
        vector<int> indegree(V,0);
        queue<int> q;
        
        //calculated each nodes indegrees
        for(int i=0;i<V;i++)
        {
            for(int x:adj[i])
            {
                indegree[x]++;
            }
        }
        
        //adding the nodes with 0 indegrees in queue
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        
        int c=0;//if count of c is equal to V then its a complete toposort possible
        while(!q.empty())
        {
            c++;
            int node=q.front();
            q.pop();
            for(int x:adj[node])
            {
                indegree[x]--;
                if(indegree[x]==0)
                q.push(x);
            }
        }
        if(V==c)return false;//if no. of toposort elements is equal to no. of elements then toposort is generated
        return true;
    }