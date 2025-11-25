#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

const int N = 1e5 + 10 ;

// try to solve fibonacci problem using recursion 

int dp[N];

// n here is the state 
int fib(int  n ){
    if(n == 0) return 0 ;
    if(n == 1) return 1;
    return fib(n -1)+ fib(n-2);
}

// Using Dynamic Programming to Optimise the Recursive Fibonacci Solution

// Top Down Approach 
// Memoisation
// TC -> 
// SC ->
int fibonacci(int  n ){
    if(n == 0) return 0 ;
    if(n == 1) return 1;
    // memoisation
    if(dp[n] != -1) return dp[n];
    return dp[n] = fibonacci(n -1)+ fibonacci(n-2);
}

// Bottom Up Approach
// Tabulation 
// SC ->  O(N)
// TC ->  O(N)

int main(){
    memset(dp , -1 , sizeof(dp));
    int n ;
    cin >> n ;
    dp[0] = 0 ;
    dp[1] = 1 ;
    for(int i = 2 ; i <= n ; ++i){
        dp[i] = dp[i-1]+ dp[i -2];
    }
    return dp[n];
}

 
// Optimize the code 
int main()
{
    memset(dp , -1 , sizeof(dp));
    int n ; 
    cin >> n ;
    prev2 = 0 ; 
    prev  =1 ;
    for(int i = 2 ; i <=n ; i++)
    {
        int curr = prev + prev2 ; 
        prev2 = prev  ; 
        prev = curr ; 
    }
    cout << prev ; 
    return 0 ;
}



int main1(){
    memset(dp , -1 , sizeof(dp));
    int n ;
    cin >> n ;
    auto start1 = chrono::system_clock::now();
    cout << fib(n) << endl;
    auto stop1 = chrono::system_clock::now();
    auto duration =  chrono::duration_cast<chrono::microseconds>(stop1 - start1);
    cout << duration.count() << endl;
    return 0;
}



