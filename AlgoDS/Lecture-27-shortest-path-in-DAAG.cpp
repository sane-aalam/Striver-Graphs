
#include <bits/stdc++.h>
using namespace std;

/*
Why Topological Sort : In previous approach source(u) se kisi node(v) tak 
pahuchane ke multiple paths ho skte he par optimal path konsa hoga, ye nhi 
pata....  isliye ham saare paths se cost nikal rhe the aur optimal cost update 
kar rhe the. So agar hme ye pata chal jaye ki node(u) se node(v) tak jane ke 
jitne bhi paths he wo paths ke sare nodes agar ham node(v) tak pahuchne se 
pahle hi mil jaye so that ham node(v) jab par pahuchege to sare paths ke 
nodes ka process kar chuke ho. To esa order , Topological Sort se milata he.
 

Ham Toposort ka use karege , Toposort se one by one node ko lekar uske adjacent  nodes nodes ka distance update kar dege (If newDistance of adjacent nodes is less than currDistance).

We are processing every node of the Toposort only one time thats why Time Complexity of this appproach is less than previous approach.

*/
class Solution {
    //Topological sort    
    vector<int> stak;
    void DFS_Topo_sort(int node, vector<vector<int>> adj[], vector<int> &visited){
        visited[node] = true;
        
        for(auto nbr : adj[node]){
            if(!visited[nbr[0]])
                DFS_Topo_sort(nbr[0], adj, visited);
        }
        stak.push_back(node);
    }
  public:
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<int>> adj[N];
        for(auto e : edges){
            adj[e[0]].push_back( {e[1], e[2]} );
        }
        //finding Toposort
        vector<int> visited(N), distance(N, INT_MAX) ;
        DFS_Topo_sort( 0, adj , visited) ;
        // reverse(stak.begin() , stak.end()) ;
        
        distance[0] = 0;
        while(stak.size())
        {
            int node = stak.back();
            stak.pop_back() ;
            
            for(auto &nbrData : adj[node]){
                int nbr = nbrData[0] ;
                int wt = nbrData[1] ;
                if(distance[node] + wt < distance[nbr]){
                    distance[nbr] = distance[node] + wt ;
                }
            }
        }
        for(auto &d : distance)
            if(d == INT_MAX)d = -1;
            
        return distance ;
    }
};
