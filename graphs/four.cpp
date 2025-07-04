// Storing Connected Components 
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
bool vis[N];
vector<int> g[N];

vector<vector<int>> cc;
vector<int> current_cc ;


// DFS in modern C++ class solution

class Solution{
	private:
		void dfs(int node , vector<int> adj[] , int vis[] , vector<int>& ls){
			vis[node] = 1;
			ls.push_back(node);

			for(auto it : adj[node]){
				if(!vis[it]){
					dfs(it , adj , vis , ls );
				}
			}
		}

	public:
		vector<int> dfsOfGraph(int n , vector<int> adj[]){

			int vis[n] = {0} ;
			int start = 0 ;
			vector<int> ls ;
			dfs(start , adj , vis , ls);
			return ls ;

		}
}

//  SC = O(N) + O(N) + O(N) = O(3N)
//  TC = O(N) + O(2*E) -- undirected graph

























void dfs(int vertex)
{
	// do things to vertex after entering vertex
	vis[vertex] = true ;
	current_cc.push_back(vertex);

	for(int child : g[vertex])
	{
		// do things to child before entering child node
		if(vis[child]) continue;
		dfs(child);
		// do things to child after exiting child node
	}
	// do things to vertex before exiting vertex
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
	
	// finding number of components 
	int ct = 0 ;
	for(int i = 0 ; i <= n ; ++i)
	{
		if(vis[i]) continue;
		current_cc.clear();
		dfs(i);
		cc.push_back(current_cc);
		ct++;
	}
	cout << cc.size() << endl;

	for(auto c : cc)
	{
		for(int vertex : c)
		{
			cout << vertex << " " ;
		}
		cout << endl;
	}

}