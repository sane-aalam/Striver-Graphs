#include <bits/stdc++.h>
using namespace std;

bool bfs(int src,vector<int> &color,vector<int>adj[]){
        queue<int> q;
        q.push(src);
        // color the node 
        color[src]=1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            // go to the adjlist node 
            // if adjist node are not colored,color with opsite color
            for(auto child:adj[node]){
                if(color[child]==-1){
                    color[child] = !color[node];
                    q.push(child);
                }
                else{
                    // it have same color that parent have 
                    // return false
                    if(color[child]==color[node]) return 0;
                }
            }
        }
        return 1;
    }