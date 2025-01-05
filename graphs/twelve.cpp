// BFS

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
	vector<int> bfs(int V , vector<int> adj[]){
		int vis[V] = {0};
		vis[0] = 1 ;
		queue<int> q;

		q.push(0);
		vector<int> bfs;

		while(!q.empty()){
			int node = q.front();
			q.pop();
			bfs.push_back(node);
			for(int it : adj[node]){
				if(!vis[it]){
					vis[it] = 1;
					q.push(it);
				}
			}
		}
		return bfs;
	}
};



void addEdge(vector<int> adj[] , int u , int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printAns(vector<int>& ans){
	for(int i =0 ; i< ans.size() ; ++i){
		cout << ans[i] << endl;
	}
}

int main()
{
	vector<int> adj[6];

	addEdge(adj , 0 , 1);
	addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Solution obj;
    vector<int> ans = obj.bfs(5 , adj);
    printAns(ans);

    return 0 ;
}

