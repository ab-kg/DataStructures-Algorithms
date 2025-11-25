#include <bits/stdc++.h> 
using namespace std  ; 

// recursion
// Infinite supply of coins  , multiple use of things ==> it will stand at the same index ; 


int recursion(int ind , int target, vector<int>& coins , vector<vector<int>>& dp  )
{
    if(ind == 0 ) {
        if(target % coins[ind] == 0 ) return target / coins[ind];
        else return 1e9 ; 
    }

    if(dp[ind][target] != -1 ) return dp[ind][target];
    
    int nottake = recursion(ind- 1 , target ,coins ,  dp );
    int take = INT_MAX ;

    if(coins[ind] <= T) take = 1 + f( ind  , target - coins[ind] ,coins ,  dp ) ; 


    return dp[ind][target]  =  min(take ,  nottaken);
}


int noofcoins(vector<int>& coins , int target)
{   
    int n = coins.size();
    vector<vector<int>> dp(n , vector<int>(target +1 , -1));

    return recursion(n-1 , target , coins , dp );
}

// recursion 
// TC == exponential 
// Sc == O(target) 


// memoization
// TC = O(N * Target)
// SC = O(N* T) + O (Target)



// tabulation
// bottom up 

// TC = O(N * target)
// SC = O(N * T ) ==> no stack space 

int noofcoins(vector<int>& coins , int target)
{
    int n = coins.size();

    vector<int> prev(target + 1 , 0 );
    vector<vector<int>> dp(n , vector<int>(target +1 , 0 ));

    for(int i = 0 ;i < target ; i++)
    {
        if(i % coins[0] == 0  ) {
            prev[i] =  i / coins[0];
        }
        else prev[i] = 1e9  ; 
    }


    for(int ind = 1 ; ind < n ; ind++)
    {   
        vector<int> curr(target + 1 , 0 );
        for(int coins = 0 ; coins <= target ; coins++)
        {
            int nottake = prev[coins];
            int take = 0 ; 
            if(coins[ind] < coins )
                take = 1 + curr[coins - coins[ind]];


            curr[coins] = min(take , nottake );
        }
        prev = curr ; 
    }


    int ans = prev[target] ;
    if(ans >= 1e9 ) return -1 ; 
    return ans; 

}



