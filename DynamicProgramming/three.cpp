// Longest Increasing Subsequence . 

#include <bits/stdc++.h>
using namespace std;
const int N = 25e2 + 10 ;
vector<int> a(N);
int dp[N];

// we can  use dp to reduce the number of calls . 
int func(int i ){
    int ans = 1 ;
    if(dp[i]  != -1) return dp[i];
    for(int j = 0 ; j < i ; ++j){
        if(a[i] > a[j]){
            ans = max(ans , func(j) + 1 );
        }
    }
    return dp[i] = ans ;
}

// Recursion Time Complexity 
int main(){
    memset(dp , -1 , sizeof(dp));
    int n ;
    cin >> n ;
    for(int i ; i <  n ; ++i ){
        cin >> a[i];
    }
    int realAnswer;
    for(int i = 0 ; i < n ; ++i){
        realAnswer = max(realAnswer , func(i));
    }
    cout << realAnswer ;
}

// DP reduces the time complexity from exponential to Linear or Quadratic . 
