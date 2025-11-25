// MINIMUM SPANNING TREE

// N nodes
// M edges

// A tree in which we have N nodes and N-1 edges & all nodes are reachable from each other 

// MST 
// Any spanning tree with least sum is called Minimum Spanning Tree

#include <bits/stdc++.h>
using namespace std ;

// how to find MST of given graph
// 1. Prim's Algorithm 
// 2. Disjoint Set
// 3. Krushkal's Algorithm


// PRIMS ALGORITHM 

// this algorithm can be extended to find the minimum spanning tree


int spanningTree(int v ,  vector<vector<int>> adj[])
{
    priority_queue<pair<int , int> , 
    vector<pair<int , int>> , greater<>> pq ;

    vector<int> vis(V , 0 );
    // just the sum of weight of MST is required
    //  {wt , node }
    pq.push({0 , 0 });
    int sum = 0 ;

    while(!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second ;
        int wt = it.first ;

        if(vis[node]) continue ;

        vis[node] = 1 ;
        sum += wt ;

        for(auto it : adj[node])
        {
            int adjNode  = it[0] ;
            int wt = it[1] ;

            if(!vis[adjNode]){
                pq.push({wt , adjNode });
            }
        }
    }

    return sum ; 
}
