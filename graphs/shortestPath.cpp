// Directed Acyclic Graph
// Find shortest path from source to all the nodes .


#include <iostream>
#include <bits/stdc++.h>

class Solution
{
public:
    vector<int> shortestPathBFS(vector<int>& edges , int N  , int M , int src)
    {
            vector<pair<int , int>> adj[];
            for(int i = 0 ;i < edges.size() ; i++)
            {
                for(int j = 0 ; j < edges[0].size() ; j++)
                {
                    if(edges[i][j])
                        adj[i].push_back({j , edges[i][j]}); 
                }
            }

        int dist[N] ;
        for(int i = 0 ;i < N ; i++)  dist[i] = 1e9 ;

        dist[src] = 0 ;

        queue<int> q; 
        q.push(src);

        while(!q.empty())
        {
            int v = q.front() ; 
            q.pop();


            for(auto it : adj[v])
            {   
                if(dist[v] + it.second < dist[it])
                    dist[it.first] = dist[v] + it.second ;
                q.push(it);
            }

        }

        return dist ;
            
    }

    void topoSort(int node , vector<pair<int , int>> adj[] , int vis[] , stack<int>& st  )
    {
        vis[node] = 1;
        for(auto it : adj[node]){
            int v = it.first ;
            if(!vis[v]){
                topoSort(v , adj , vis , st );
            }
        }

        st.push(node);
    }


    vector<int> shortestpathDFS(vector<int>& edges , int N  , int M , int src)
    {
            vector<pair<int, int>> adj[N] ;
            for(int i  = 0 ;i < M ; i++)
            {
                int u = edges[i][0]  ;
                int v = edges[i][1]  ;
                int wt = edges[i][2] ;
                adj[u].push_back({v , wt});
            }

            int vis[N] = {0};
            stackt<int> st;
            for(int i = 0 ;i < N ; i++)
            {
                if(!vis[i])
                    topoSort(i , adj , vis , st);
            }



            //step2 
            vector<int> dist(N) ;
            for(int i = 0 ;i < N ; i++) dist[i] = INT_MAX ;
            dist[0] = 0 ;

            while(!st.empty())
            {
                int node = st.top();
                st.pop();

                for(auto it : adj[node])
                {
                    int v = it.first ;
                    int wt = it.second ;

                    if(dist[node] + wt < dist[v]){
                        dist[v] = dist[node] + wt ;
                    }
                }
            }
            return dist;
    }



}