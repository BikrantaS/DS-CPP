https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
//Cycle Detection in Directed Graph using DFS
TC:N+E SC:2N+N
bool dfscycle(int node, vector<int> adj[],vector<int>& vis,vector<int>& currvis)
     {
         //setting current and visited nodes to 1
         vis[node]=1;
         currvis[node]=1;
         for(int x:adj[node])
         {
             if(vis[x]==0)
             {
                if(dfscycle(x,adj,vis,currvis)==true)//if any node return true,the cycle is detected
                return true;
             }
             else if(currvis[x]==1)//means vis[node]==1 && currvis[node]==1
             return true;
         }
         currvis[node]=0;//setting current nodes to 0,for backtrackking
         return false;
     }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);//to store wheter the nodes are visited or not.
        vector<int> currvis(V,0);//to store wheter current nodes are visited or not.
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                if(dfscycle(i,adj,vis,currvis)==true)
                return true;
            }
        }
        return false;
    }