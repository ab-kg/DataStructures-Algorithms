// Basic Questions on DFS 

// DFS Concepts
// - Connected Components
// - Finding a loop in a graph 

#include <bits/stdc++.h>
using namespace std;

// 	TRAVERSAL ALGROITHM 
// 	DEPTH FIRST SEARCH 

// 1. Connected Components
const int N = 1e5 + 10 ;

bool vis[N];
vector<int> g[N];

void dfs(int vertex){
	// Take action on vertex after entering the vertex
	vis[vertex] = true ;
	for(int child : g[vertex]){
		if(vis[child]) continue;
		// Take action on child before entering the child node 
		dfs(child);
		// Take action on child after exiting child node
	}
	// Take action on vertex before exiting the vertex 
}

int main(){
	int n , e ; 
	cin >> n >> e ;
	
	for(int i =0  ; i < e ; ++i){
		int x , y ;
		cin >> x >> y ; 
		g[x].push_back(y);
		g[y].push_back(x);
	}

	// finding the number of components  
	int ct = 0 ;
	for(int i = 1 ; i <= n ; ++i){
		if(vis[i]) continue;
		dfs(i);
		ct++;
	}
	cout << ct << endl; 
}