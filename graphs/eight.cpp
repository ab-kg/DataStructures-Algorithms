// Diameter of a Treeee
// -- Number of edges between two vertices in a tree 

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];

int depth[N] ;

// Optimised way to calculate diameter of a tree
// 1. With any root find max depth node
// 2. With that node as root find max depth 


void dfs(int v , int par = -1)
{
	for(int child : g[v]){
		if(child == par) continue;
		depth[child] = depth[v] + 1 ;
		dfs(child , v);
	}
}


int main()
{
	int n ;
	cin >> n ;
	for(int i = 0 ; i < n-1 ; ++i)
	{
		int x , y ;
		cin >> x >> y ;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1);
	int max_depth = -1;
	int max_d_node ;

	for(int i = 1 ; i <= n ; ++i){
		if(  max_depth < depth[i]  ){
			max_depth = depth[i];
			max_d_node = i ;
		}
		depth[i] = 0 ;
	}

	dfs(max_d_node);
	max_depth = -1 ;
	for(int i = 1 ; i <= n ; ++i){
		if(max_depth < depth[i]){
			max_depth = depth[i];
		}
	}

	cout << max_depth << endl;

}

