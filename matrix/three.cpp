// Number of subarrays with sum K 
#include <bits/stdc++.h>

using namespace std;

// O(N^3)
int bruteforce(int k )
{
    vector<int> arr = { 1 , 2,  3 , -3 , 1 , 1 , 1, 4 , 2 , -3};
    int count = 0 ;
    for(int i = 0 ;i < arr.size() ; i++)
    {
        for(int j = 0 ; j < arr.size() ; j++)
        {
            int sum = 0 ;
            for(int k = i ; k < j ; k++)
            {
                sum += arr[k];
            }
            if(sum == k )
            {
                count++;
            }
        }
    }
    return count;
}

// O(N^2)
int bettersolution1(int k){
    vector<int> arr = { 1 , 2,  3 , -3 , 1 , 1 , 1, 4 , 2 , -3};
    int count = 0 ;
    for(int i = 0 ;i < arr.size() ; i++)
    {   
        int sum = 0 ;
        for(int j = 0 ; j < arr.size() ; j++)
        {
            sum += arr[j];
        }
        if(sum == k) count++;
    }
    return count;
}

// Optimal Solution using Prefix Sum 
// O(N* logN) - TC
// O(N) - SC
int optimalSolution(int k)
{   
    vector<int> arr = { 1 , 2,  3 , -3 , 1 , 1 , 1, 4 , 2 , -3};
    unordered_map<int , int >  map;
    int prefix = 0 ;
    int count = 0 ;
    int remove = 0 ;
    for(int i =0  ;i < arr.size() ; i++){
        prefix += arr[i];
        remove = prefix - k;
        count += map[remove];
        map[prefix] += 1;
    }
    return count;
}
