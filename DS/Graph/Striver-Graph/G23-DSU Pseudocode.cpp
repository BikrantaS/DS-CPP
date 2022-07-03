int parent[100000];
int rank[100000];

void makeSet()
{
	for(int i=1;i<=n;i++)
	{
		parent[i]=i;
		rank[i]=0;
	}
}



int findPar(int node)
{
	if(node==parent[node])
		return node;

	return paren[node]=findPar(parent[node]);//Path compression
}

//TC:4*α
void union(int u,int v)
{
	u=findPar(u);
	v=findPar(v);

	if(rank[u]<rank[v])
		parent[u]=v;

	else if(rank[v]<rank[u])
		parent[v]=u;

	else
	{
		parent[v]=u;
		rank[u]++;
	}
}

void main()
{
	makeSet();
	int m;cin>>m;
	while(m--)
	{
		int u,v;
		union (u,v);
	}

	//If 2 and 3 belong to the same component or not
	if(findPar(2)!=findPar(3))
		cout<<"Different Componnent";
	else
		cout<<"Same Componnent";
}