// recurison 

// express in terms of (index , weights)
// explore all possibilites ==> pick and non ==> DP on subsequences 
// max of all possibilities 

#include <bits/stdc++.h> 
using namespace std  ; 

int recursion(int ind , int weights , vector<int>& nums )
{

    // base case 
    if(ind == 0 && weight[0] <= weights)
    {
        return nums[0];
    }
    else
    {
        return 0 ; 
    }

    // explore
    int notsteal = recursion(ind -1 , weights , nums );
    int steal = 0 ; 
    if(nums[ind] <= weights)
        steal = recursion(ind -1 , weights , nums ) ; 
    
    return max(steal , notsteal) ; 
}


// tabulation
// base case in dp[matrxi]
// express the changing variables in dp[][] matrix in loops
// repeat the recursive steps

int f(int ind , int w , vector<int>& weight , vector<int>& value)
{
    if(ind == 0 )
    {
        if(weight[0] <= w) return value[0];
        return 0 ; 
    }

    int nottake = f(ind -1 , w , weight , value) ; 
    int take = INT_MIN ; 
    if(weight[ind] <= w)
        take = value[ind] + f(ind -1 , w - weight[ind] , weight , value);
    
    return max(nottake , take);
}

int knapsack(vector<int> weight , vector<int> value , int n , int maxWeight )
{
    vector<vector<int>> dp(n , vector<int> (maxWeight + 1 , -1));
    return f(n-1 , maxWeight , weight , value , dp );
}

