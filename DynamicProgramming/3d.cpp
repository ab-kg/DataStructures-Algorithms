#include <bits/stdc++.h> 

int recursion(int i1 , int j1    ,int j2 , int r , int c ,  vector<vecotr<int>>& grid , vector<vector<vector<int>>>& dp  )
{
        if(j1 < 0 || j1 >= c || j2 < 0  || j2 >= c ) return -1e8 ;

        if(i1 == n - 1) 
        {
            if(j1 == j2 ) return grid[i][j2];
            else {
                return grid[i][j1] + grid[i][j2];
            }
        }

        if(dp[i1][j1][j2]  != -1 ) return dp[i1][j1][j2];
        
        int maxi = INT_MIN ; 
        for(int dj1 = -1 ; dj1 < 2 ; dj1 ++ )
        {
            for(int dj2 = -1 ; dj2 < 2 ; dj2 ++ )
            {   
                int value = 0 ; 
                if(dj1 == dj2) 
                {
                    value  =  grid[i1][j1]  ;
                }
                else 
                {
                    value =  grid[i1][j1] + grid[i1][j2]  ; 
                }
                value += recursion( i1 + 1 , j1 + dj1 , j2 + dj2 ,r , c ,  grid , dp )
                maxi = max(maxi , value );
            }
        }
        return  dp[i1][j1][j2] =  maxi ; 
}



int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>>& dp(r , vector<vector<int>>(c , vector<int>(c , -1)));

    int ans = recursion(0 , 0 , c-1 , r , c , grid , dp );

    return ans ; 
}