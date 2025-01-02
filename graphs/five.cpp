// How to find if the graph has cycle ?
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
bool vis[N];
vector<int> g[N];

bool dfs(int vertex , int par)
{
	// do things to vertex 
	vis[vertex] = true ;
	bool isLoopExists = false;
	for(auto child : g[vertex])
	{
		// do things to child before entering into child
		if(vis[child] && child == par) continue ;
		if(vis[child]) return true ;
		isLoopExists |=	dfs(child  , vertex);
		// do things to child after exiting from child
	}
	// do things to verted before exiting vertex 

	return isLoopExists;
}


int main()
{
	int n , e ;
	cin >> n >> e ;

	for(int i = 0 ;i < e ; ++i)
	{
		int x , y ;
		cin >> x >> y ;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	int ct = 0 ;
	bool isLoopExists = false;
	for(int i =1 ; i <= n  ; ++i)
	{
		if(vis[i]) continue;
		if(dfs(i , 0 )){
			isLoopExists = true ;
			break;
		}
	}

	cout << isLoopExists << endl;

}