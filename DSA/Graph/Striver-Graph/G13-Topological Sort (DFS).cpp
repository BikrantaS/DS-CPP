https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
//Topological Sort (DFS)
//TC:N+E SC:2N+N

public:
	//Function to return list containing vertices in Topological order. 
	//DFS technique
	void dfstopo(int node, vector<int> adj[], vector<int>& vis, vector<int>& st)
	{
	    vis[node]=1;
	    for(int x:adj[node])
	    {
	        if(vis[x]==0)
	        dfstopo(x,adj,vis,st);
	    }
	    st.push_back(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> topotraversal;
	    vector<int> st;
	    vector<int> vis(V,0);
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==0)
	        dfstopo(i,adj,vis,st);
	    }
	    
	    while(!st.empty())
	    {
	        topotraversal.push_back(st.back());
	        st.pop_back();
	    }
	    return topotraversal;
	}