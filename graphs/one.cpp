// GRAPHS AND TREES

// what are graphs and tress
// ṛepresentation of graphs and trees

// HOW TO REPRESENT TREES AND GRAPHS IN CODE 

#include <bits/stdc++.h>
using namespace std;

// const int N = 1e3+10 ;
// int graph1[N][N] ;

// vector<int> graph2[N];
// with weights
// vector<pair<int, int>> graph2[N]

int main(){
    int n , m ;
    cin >> n >> m ;

    // Adjancency Matrix
    // O(N^2) - space complexity 

    int adj[n+1][m+1];
    for(int i = 0 ; i < m ; i++){
        int u , v ; 
        cin >> u >> v ;
        adj[u][v] = 1 ;
        adj[v][u] = 1 ;
    }

    // for waited graph
    for(int  i = 0 ; i < m ; i++){
        int u , v , wt ; 
        cin >>  u >> v >> wt ; 
        adj[u][v] = wt ;
        adj[v][u] = wt ;
    }

    return 0 ;
}

// Adjacency List 

int main2()
{   
    int n , m ; 
    cin >> n >> m ; 
    vector<int> adj[];

    for(int i = 0 ; i < m ; i++){
        int u , v ; 
        cin >> u >> v ; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // for waited graph
    vector<pair<int , int>> adj[];

    for(int i =0 ;i < m ; i++){
        int u , v  , wt ;
        cin >> u >> v >> wt  ; 
        adj[u].push_back({v , wt});
        adj[v].push_back({u , wt});
    }

    return 0 ;
}


