
//Shotest Path from source in weighted DAG

void topoSort(int node,int vis[],stack<int>& st,vector<pair<int,int>> adj[])
{
	vis[node]=1;
	for(auto it:adj[node])
	{
		if(!vis[it.first])
			topoSort(it.first,vis,st,adj);
	}
	st.push(node);
}

void shotestPath(int src,int N,vector<pair<int,int>> adj[])
{
	int vis[N]={0};
	stack<int> st;
	for(int i=0;i<N;i++)
		if(!vis[i])
			topoSort(i,vis,st,adj);

	int dist[N];
	for(int i=0;i<N;i++)
		dist[i]=1e9;
	dist[src]=0;

	while(!st.empty())
	{
		int node=st.top();
		st.pop();

		if(dist[node]!=INF)
		{
			for(auto it:adj[node])
			{
				if(dist[node]+it.second<dist[it.first])
					dist[it.first]=dist[node]+it.second;
			}
		}
	}

	for(int i=0;i<N;i++)
		(dist[i]==1e9)?cout<<"INF ":cout<<dist[i]<<" ";


}