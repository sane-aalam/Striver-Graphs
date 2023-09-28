
#include <bits/stdc++.h>
using namespace std;

//1st think about which one the best for this queue/ priority-queue

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    
        // case 1 : create the adj list 
       vector<int> adj[N];
    
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
       
       // case 2 : need a queue data structure and dis array
       vector<int> dis(N);
       
       for(int i = 0; i<N; i++){
           dis[i] = INT_MAX;
       }
       
       queue<int> q;
       q.push(src);
       // push the node starting into the quque data structrue
       dis[src] = 0; // itself contain zero weight
       
       // case 3 : perfom disjtra algoritm (BFS)
       while(!q.empty()){
           int node = q.front();
           q.pop();
           
           for(auto it : adj[node]){
               if(dis[node] + 1 < dis[it]){
                   dis[it] = dis[node] + 1;
                // push into the queue, adj nodes all 
                   q.push(it);
               }
           }
       }
      // copy the all distance into the array 
      // but does't include infinte disination 
      vector<int> ans(N,-1);
      for(int i = 0; i<N; i++){
          if(dis[i]!= INT_MAX){
              ans[i] = dis[i];
          }
      }
      // return the ansewr 
      return ans;
    }
};
