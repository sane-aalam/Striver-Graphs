

//* Basic code to cover to all sub-graphs
//* need visted arary to maintain 
// this node is visited or not
// this node is already done,don't perform task

#include <bits/stdc++.h>
using namespace std;

int V = 10;
// starting all node mark unvisted 
vector<int> visted(V,0);
for(int i = 0; i<V; i++){
    if(visted[i] == 0){
        // call traversal algorithm
        // like- DFS / BFS algorithm called
    }
}