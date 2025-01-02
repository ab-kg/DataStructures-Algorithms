// Dynamic Programming is just a wrapper on Recursive Code . 

#include<bits/stdc++.h>
using namespace std;

static int i = 0 ;
void func(int n ){
    if (n == 0) return  ;
    func(n-1);
    cout << n << endl;
}

int factorial(int n )
{
    if(n == 0 ) return 1 ;
    return n*factorial(n-1);
}

// Time Complexity 
// 1. Number of function calls              -> n
// 2. What is complexity of each function   -> O(1)
// Total Time Complexity ==> O(N)

int main(){
    int n ;
    cin >> n ;
    cout << factorial(n) << endl;
}

// infinite recursion 
// implementation of recursion is using stack 
// segmentation fault is stack overflow 
