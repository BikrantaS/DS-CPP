//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V,INT_MAX);//stores distance array
        
        //declare a min-heap using priority queue {weight,node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        //distance of source to source is obvioulsy Zero.
        dist[S]=0;
        
        //insert the distance and source in priority-queue
        pq.push({0,S});
        
        while(!pq.empty())
        {
            int distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto x:adj[node])
            {
                int next_distance=x[1];
                int next_node=x[0];
                
                //relaxation:
                if(dist[node]+next_distance<dist[next_node])
                {
                    dist[next_node]=next_distance+dist[node];
                    pq.push({dist[next_node],next_node});
                }
            }
        }
        return dist;
    }