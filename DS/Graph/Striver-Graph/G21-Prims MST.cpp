//Efficent Approach TC:NlogN + (N+E)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,m;
    cin >> N >> m;
    vector<pair<int,int> > adj[N]; 

    int a,b,wt;
    for(int i = 0; i<m ; i++){
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));
    }   
    
    int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});
    // Run the loop till all the nodes have been visited
    // because in the brute code we checked for mstSet[node] == false while computing the minimum
    // but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
    // hence its better to keep running till all the nodes have been taken. 
    // try the following case: 
    // Credits: Srejan Bera
    // 6 7 
    // 0 1 5 
    // 0 2 10 
    // 0 3 100 
    // 1 3 50 
    // 1 4 200
    // 3 4 250
    // 4 5 50 
    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
        key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    } 
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
    return 0;
}


//////////////////////////////////////////////////////////////////////////

//Inefficent Approach TC:N^2
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N=5,m=6;
    vector<pair<int,int> > adj[N]; 


    adj[0].push_back({1,2});
    adj[0].push_back({3,6});
    adj[1].push_back({0,2});
    adj[1].push_back({2,3});
    adj[1].push_back({3,8});
    adj[1].push_back({4,5});
    adj[2].push_back({1,3});
    adj[2].push_back({4,7});
    adj[3].push_back({0,6});
    adj[3].push_back({1,8});
    adj[4].push_back({1,5});
    adj[4].push_back({2,7});
    
    int parent[N];
    int key[N]; 
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    key[0] = 0; 
    parent[0] = -1; 
    int ansWeight = 0;
    for (int count = 0; count < N - 1; count++)
    { 
        
        int mini = INT_MAX, u; 
  
        for (int v = 0; v < N; v++) 
{
            if (mstSet[v] == false && key[v] < mini) 
                mini = key[v], u = v; 
}
                 mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) 
                parent[v] = u, key[v] = weight; 
        }
            
    } 
    
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
    return 0;
}


//////////////////////////////////////////////////////////////////////////

// THE GFG practice section problem has faulty test case, it says the nodes are 0-based, but it has 0-based nodes and also has nodes which are names as N. 
// Hence be careful while submitting the code at GFG
// THe below code runs fine. 

class Solution
{
    public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int N, vector<vector<int>> adj[])
    {
        int parent[N+1]; 
          
        int key[N+1]; 
          
        bool mstSet[N+1]; 
      
        for (int i = 0; i <= N; i++) 
            key[i] = INT_MAX, mstSet[i] = false; 
        
        priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
    
        key[0] = 0; 
        parent[0] = -1; 
        pq.push({0, 0});
        while(!pq.empty())
        { 
            int u = pq.top().second; 
            pq.pop(); 
            
            mstSet[u] = true; 
            
            for (auto it : adj[u]) {
                int v = it[0];
                int weight = it[1];
                if (mstSet[v] == false && weight < key[v]) {
                    parent[v] = u;
            key[v] = weight; 
                    pq.push({key[v], v});    
                }
            }
                
        }
        int sum = 0;
        for(int i = 1;i<=N;i++) {
            if(key[i] != INT_MAX) sum += key[i];
        }
        return sum; 
    }
};

///////////////////////////////////////////////////////////////////////////


//Efficent Approach
int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Prims's Algorithm for MST(Using Priority Queue)
        bool mstSet[V];//stores wheter the ith node is part of MST or not
        int dist[V];//stores distance of ith element from previous node
        int parent[V];//stores parent of ith element
        for(int i=0;i<V;i++)
        {
            mstSet[i]=false;//setting all ith nodes that initially all false
            dist[i]=INT_MAX;//In Prim's Algo we initially asume each node has infinity distance from previous node
            parent[i]=-1;//Every ith node's initial parent is -1
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        dist[0]=0;//setting distance from first node to 0 
        int sum_of_weights=0;//To store sum od distances that are part of MST
        while(!pq.empty())
        {
            
            int u=pq.top().second;//variable to store the desired node from priority queue which has least distance 
            pq.pop();
            
            mstSet[u]=true;//now the desired node which has least distance is part of MST
            
            for(auto x:adj[u])//traverse all adjacent nodes of the current MST node
            {
                int node=x[0];//current adjacent node
                int weight=x[1];//current adjacent node distance
                
                if(mstSet[node]==false && weight<dist[node])
                {//if the current adjacent node is not prevously part of MST and its weight is less than its initialized node then do this.
                    parent[node]=u;//The parent of current node now is its parent node,previouly it was -1.
                    dist[node]=weight;//current node's  new distance becomes its actual weight from infinity
                    pq.push({dist[node],node});//Insert the newly found relaxed node in the priority queue
                    
                }
            }
           
        }
        
        //Summing up the weights of MST
         for(int i=1;i<V;i++)
            sum_of_weights+=dist[i];
        return sum_of_weights;
        
        
        //NOTE:Here we are not using the parent[V] array because it is used
        //to print the nodes of MST and here we are just printing the sum of final weights
        
    }

////////////////////////////////////////////////////////////////////////

//Ineffficient apparoach
//TC:N^2

//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Prims's Algorithm for MST(Brute force approach)
        bool mstSet[V];//stores wheter the ith node is part of MST or not
        int dist[V];//stores distance of ith element from previous node
        int parent[V];//stores parent of ith element
        for(int i=0;i<V;i++)
        {
            mstSet[i]=false;//setting all ith nodes that initially all false
            dist[i]=INT_MAX;//In Prim's Algo we initially asume each node has infinity distance from previous node
            parent[i]=-1;//Every ith node's initial parent is -1
        }
        
        
        dist[0]=0;//setting distance from first node to 0 
        int sum_of_weights=0;//To store sum of distances that are part of MST
        for(int i=0;i<V-1;i++)
        {
            int mini=INT_MAX;//variable to store the minimum weight which is not currentlty part of MST
            int u;//variable to store the desired node which has least distance
            for(int j=0;j<V;j++)
            {
                if(mstSet[j]==false && dist[j]<mini)
                {
                    mini=dist[j];
                    u=j;
                }
            }
            
            mstSet[u]=true;//now the desired node which has least distance is part of MST
            
            for(auto x:adj[u])//traverse all adjacent nodes of the current MST node
            {
                int node=x[0];//current adjacent node
                int weight=x[1];//current adjacent node distance
                
                if(mstSet[node]==false && weight<dist[node])
                {//if the current adjacent node is not prevously part of MST and its weight is less than its initialized node then do this.
                    dist[node]=weight;//current node's  new distance becomes its actual weight from infinity
                    parent[node]=u;//The parent of current node now is its parent node,previouly it was -1.
                }
            }
           
        }
        
        //Summing up the weights of MST
         for(int i=0;i<V;i++)
            sum_of_weights+=dist[i];
        return sum_of_weights;
        
        
        //NOTE:Here we are not using the parent[V] array because it is used
        //to print the nodes of MST and here we are just printing the sum of final weights
        
    }