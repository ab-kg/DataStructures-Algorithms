class Solution { 
private:
    // Function to detect cycle in an undirected graph.
    bool dfs(int src , vector<int>& vis , vector<vector<int>> &adj  )
    {
        vis[src]= 1;
        for(auto adjacentNode : adj[src]){
            if(!vis[adjacentNode]){
                if(dfs(adjacentNode , node , vis , adj) == true ) return true ;
            }
            else if(adjacentNode != parent) return true ;
        }
    }
    
public:
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int v = adj.size();
        vector<int> vis(v+1 , 0);
        
        for(int i = 0 ; i < v ; ++i){
            if(!vis[i]){
                if(dfs(i, vis , adj))
                    return true ;
            }
        }
        
        return false;
    }
};