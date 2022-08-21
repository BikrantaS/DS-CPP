
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



//Ineffficient apparoach

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
        int sum_of_weights=0;//To store sum od distances that are part of MST
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