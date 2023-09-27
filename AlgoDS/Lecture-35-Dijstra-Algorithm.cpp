#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // case-1 create the queue dsa and distance infinite array
        // i can use queue. pritory queue 
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        queue<pair<int,int>> q;
        vector<int> distance(V);
        
        for(int i = 0; i<V; i++){
            distance[i] = 1e9;
        }
        
        // case-2 push into the queue dsa and put the distance himself zero
        q.push({S,0});
        distance[S] = 0;
        
        while(!q.empty()){
            int node = q.front().first;
            int dis = q.front().second;
            q.pop();
            
            // go the adjlist node 
            for(auto it : adj[node]){
                // wiehgt graphs two value contains 
                int adjNode = it[0];
                int adjWeight = it[1];
                
                // 15 + 4  < infinte then replace the value 
                // we have minimum shorted path,we can store minimum wieghts
                if(dis + adjWeight < distance[adjNode]){
                    distance[adjNode] = dis + adjWeight;
                    q.push({adjNode,distance[adjNode]});
                }
            }
        }
        return distance;
    }
};