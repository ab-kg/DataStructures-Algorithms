// here we are doing topological sort 
// we need DAG directed acylical graph to do topological sort

// number should come before number according to the direction in the graph
#include <bits/stdc++.h>
using namespace std;


void dfs(int i , int vis[] , stack<int>& st , vector<int> adj[])
{
    vis[node] = 1;
    for(auto it : adj[node])
    {
        if(!vis[it])  dfs( it , vis , st , adj);
    }
    st.push(node);
}


vector<int> topoSort(int V , vector<int> adj[])
{
    int vis[V] = {0};
    stack<int> st ;
    for(int i =0 ; i < V ; i++)
    {
        if(!vis[i]){
            dfs(i , vis , st , adj);
        }
    }

    vector<int> ans ;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}


// Kahn's Algorithm Topological Sort (BFS ) 

vector<int> KahnsTopoSort(int V , vector<int> adj[])
{
    int indegree[V] = {0};
    for(int i = 0 ; i < V ; i++)
    {
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q ;
    for(int i = 0 ; i < V ; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        top.push_back(node);

        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0 ) q.push(it);
        }
    }

    return topo ;
}

