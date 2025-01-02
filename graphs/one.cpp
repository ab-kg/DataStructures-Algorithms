// GRAPHS AND TREES

// what are graphs and tress
// ṛepresentation of graphs and trees

// HOW TO REPRESENT TREES AND GRAPHS IN CODE 

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int graph1[N][N] ;


vector<int> graph2[N];
// with weights
// vector<pair<int, int>> graph2[N]

int main(){
    int n , m ;
    cin >> n >> m ;

    for(int i = 0 ; i < m ; ++i){
        int v1 , v2  , wt;
        cin >> v1 >> v2 >> wt ;
        graph1[v1][v2] = 1;
        graph1[v2][v1]= 1 ;

        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1);

        // with weights
        graph2[v1].push_back({v2 , wt});
        graph2[v2].push_back({v1 , wt})

    }

    // Adjancency Matrix
    // O(N^2) - space complexity 
    // N = 10^5

    // Adjancency List
    // O(N + M )

    return 0 ;
}
