// here the problem is same as knapsack except the the items in the array are infinites which means we can pick the same thing 
// again and again as far as we are not going above thiefs maximum weight carrying capacity .

#include <bits/stdc++.h> 
using namespace std  ; 

// recursion
// express interms of index and base case 
//


int recursion(int n , int w , vector<int>& val, vector<int>& wt , vector<vector<int>>& dp  )
{
    if (ind == 0) {
        // Calculate and return the maximum value for the given weight limit
        return (W / wt[0]) * val[0];
    }

    if(dp[n][w] != -1) return dp[n][w];

    int notsteal = 0 +  recursion(n -1 , w , val , wt , dp );
    int steal  = INT_MIN ; 
    if(wt[n] <= w)
        steal = val[n] +  recursion(n  , w - wt[n] , val , wt , dp ) ;

    return dp[n][w] =  max(steal + notsteal) ; 
}

int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));

    return recursion(n-1 , W , val , wt , dp  );
}

// TC ==> O( N * W )
// SC ==> O(N * W) +  ==> it can be more than this also O(N)

// tabulation approach 

int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(W + 1, 0 ) );
    // vector<int> prev
    vector<int> cur(W + 1, 0);

    for(int w = 0 ; w < W ; w++)
    {
        curr[w] = (w/wt[0]) * val[0];
    }


    for(int i = 1 ; i < n ; i++ )
    {
        for(int w = 0 ; w <= W ; w++)
        {
            int nottake = curr[w];
            int take = INT_MIN ; 
            if(wt[i] <= w)
                take = val[i] + curr[w - wt[i]];

            curr[w] = max(nottake + take) ; 
        }
    }

    return curr[W];

}

// Tabulation + space optimised 

// TC = O(N* W)
// SC = O(W)


