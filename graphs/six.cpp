// How to DFS in a tree
 
// Height of leaf is zero
// Depth of root is zero

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
bool vis[N];

vector<int> g[N];

int depth[N] , height[N];

// dfs on vertex 
void dfs(int vertex , int par)
{	
	// do things to vertex after entering vertex 
	vis[vertex] = true ;
	for(int child : g[vertex])
	{	
		// do things on child before entering child
		if(child == par) continue ;
		depth[child] = depth[vertex] + 1 ;
		dfs(child , vertex);
		// do things on child after exiting child node
		height[vertex] = max(height[vertex] , height[child]+1);
	}
	// do things on vertex before exiting child node 
}

// visited array is not necessary for tree . 

int main()
{
	int n ; 
	cin >> n ;

	for(int i = 0 ;i < n-1 ; ++i){
		int x , y ;
		cin >>x >> y ;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1 , 0);

	for(int i = 1 ; i <= n ; ++i){
		cout << depth[i] << " " << height[i] << endl;
	}
}
