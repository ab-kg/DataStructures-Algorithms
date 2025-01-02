#include<bits/stdc++.h>
using namespace std;

// how to recursively find the sum of array until given index 

int arraySum(vector<int> arr , int n )
{
    if(n < 0) return 0 ; 
    return arr[n] + arraySum(arr , n-1);
}

int digitSum2(int n){
    int sum = 0 ;
    while(n > 0){
        sum += n%10;
        n = n/10;
    }
    return sum ;
}

int digitSum(int n)
{
    if(n == 0) return 0;
    return digitSum(n/10) + n%10;
}

int main()
{   
    vector<int> me = { 1 , 2  ,3 , 4  };
    // int num = arraySum(me , me.size()-1);
    int num = digitSum(1234);
    cout << num << endl;
    return num ;
}
