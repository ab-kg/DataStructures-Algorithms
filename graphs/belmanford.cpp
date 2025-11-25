// BELMAN FORD 

// directed graphs
// negative edge weight can be worked out unlike dijstrkas algo
// negative cycle == total edge sum over a cycle is negatvie then it is a negative cycle

// Undirected Graphs 
// 1 ---- 2 

// Convert into directed grpahs
// 1 ---> 2 
// 2 ---> 1 

// * Relax all the edges N - 1 times sequentially
//  Relaxation
  
//  if(dist[u] + wt < dist[v])
//  {
//     dist[v] = dist[u] + wt ;
//  }

#include <bits/stdc++.h>
using namespace std ;

vector<int> BellmanFord(int V , vector<vector<int>>& edges , int S )
{
    vector<int> dist(V , 1e8);
    dist[S] =  0 ;

    for(int i = 0 ;i < V -1 ; i++)
    {
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt  ;
            }
        }
    }

    // it contains negative cycle
    // negative cycle detection by bellman ford algorithm
    
    for(auto it : edges )
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if(dist[u] != 1e8 && dist[u] + wt < dist[v])
        {
            return {-1 };
        }
    }

    return dist ;
}