// FROG JUMP PROBLEM 

// Memoization 
#include <bits/stdc++.h>

using namespace std;

int solve(int ind, vector<int>& height, vector<int>& dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int jumpTwo = INT_MAX;
    int jumpOne= solve(ind-1, height,dp)+ abs(height[ind]-height[ind-1]);
    if(ind>1)
        jumpTwo = solve(ind-2, height,dp)+ abs(height[ind]-height[ind-2]);
    
    return dp[ind]= min(jumpOne, jumpTwo);
}

int main() {

  vector<int> height{30,10,60 , 10 , 60 , 50};
  int n=height.size();
  vector<int> dp(n,-1);
  cout<<solve(n-1,height,dp);
}


// tabulation approach

int main2()
{
  vector<int> height{30,10,60,10,60,50};
  int n=height.size();
  vector<int> dp(n,-1);
  dp[0]=0;

  for(int i = 1 ; i < n ; i++)
  {
    int jump2 = INT_MAX ; 
    int jump  = dp[i -1 ] + abs(heights[i] - heights[i -1 ]);
    if(i > 1)
        jump2 = dp[i -2 ] + abs(heights[i] - heights[i - 2]);
    
    dp[i] = min( jump , jump2 );
  }

  cout << dp[n-1 ];

}


// Space optimization APproach 

int main3
{
    vector<int> height{30,10,60,10,60,50};
  int n=height.size();
  int prev = 0 ; 
  int prev2 = 0 ; 

  for(int i =1 ; i < n ; i++)
  {
    int jump2 = INT_MAX ; 
    int jump1 = prev + abs(height[i] - height[i - 1]);
    if(i > 1 )
        jump2 = prev2 + abs(height[i] - height[i - 2]);

    int curi = min(jump1 , jump2);
    prev2 = prev ; 
    prev = curi ;
  }

  cout << prev ; 
}



