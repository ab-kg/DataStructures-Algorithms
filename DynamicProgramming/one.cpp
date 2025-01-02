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
int fibonacci(int  n ){
    if(n == 0) return 0 ;
    if(n == 1) return 1;
    // memoisation
    if(dp[n] != -1) return dp[n];
    return dp[n] = fibonacci(n -1)+ fibonacci(n-2);
}

// Bottom Up Approach
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



