// DFS Subtrees Questions
// - Precomputation using DFS
// - Subtree sum queries
// - Even odd counts in subtree

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
bool vis[N];

/*
Given Q Queries , Q <= 10^5 
In each query given V , 
Print subtree sum of V & Number of even numbers
in subtree of V
*/

vector<int> g[N];

int subtree_sum[N];
int evenCount[N];

void dfs(int vertex , int par)
{	
	subtree_sum[vertex] += vertex ;
	if(vertex %2 == 0) evenCount[vertex]++;
	for(int child : g[vertex])
	{
		if(child == par) continue;
		dfs(child , vertex);
		subtree_sum[vertex] += subtree_sum[child] ;
		evenCount[vertex] += evenCount[child];
	}
}


int main()
{
	int n ; // n number of nodes
	cin >> n ; // n-1 number of edges 

	for(int i = 0 ; i < n-1 ; ++i)
	{	
		int x ,y ;
		cin >> x >> y ;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1, 0 );
	for(int i = 1 ;  i <= n ; ++i)
	{
		cout << subtree_sum[i] << " " << evenCount[i] << endl;
	}	

}