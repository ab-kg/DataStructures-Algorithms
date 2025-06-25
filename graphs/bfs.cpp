// Breadth First Search
// Level Wise Traversal 

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bfs(int V , vector<int> adj[])
    {
        int vis[n] = {0};
        vis[0] = 1 ;
        queue<int> q ; 
        q.push(0);
        
        vector<int> bfs ;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push(node);

            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1 ;
                    q.push(it);
                }
            }
        }

        return bfs ;
    }
}


// SC = O(3N) 
// TC = O(N) + O(2E) 

