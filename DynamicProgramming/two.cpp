// A - Frog 1

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
// using namespace std;

const int N = 1e5 + 10 ;

// Brute force Recursion Approach

int h[N];
int arr[N];

int func2(int i )
{
    int cost = INT_MAX ;
    
    // way 1 
    cost = std::min(cost , func(i -1) + abs(h[i] + h[i-1]));

    // way 2
    cost = std::min(cost , func(i - 2) + abs(h[i] + h[i-2]));
    return cost ;
}

// using DP
int func(int i )
{
    int cost = INT_MAX ;
    if(i == 0 ) return 0;
    if(arr[i] != -1) return arr[i];
    // way 1 
    cost = std::min(cost , func(i - 1) + abs(h[i] + h[i-1]));

    // way 2
    if( i> 1 )
    cost = std::min(cost , func(i - 2) + abs(h[i] + h[i-2]));
    return arr[i] = cost ;
}

// FROG - 2 

int func3(int i  , int k ){
    int cost = INT_MAX ;
    if(arr[i] != -1) return arr[i];
    for(int j = 1 ; j <= k ; ++j){
        if( i - k >= 0)
        cost =  std::min(cost , func(i - j) + abs(h[j] + h[j - 2]));
    }
    return arr[i] = cost ;
}
 
int main()
{
    int n ;
    std::cin >> n ;
    for(int i = 0 ; i < n ; ++i)
    {
        std::cin >> arr[i];
    }
    
}