// number of subarrays in an array to have the xor value to be the target value . 
#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> a , int k){
    int n = a.size();
    int cnt = 0 ;

    // Brute force approach
    for(int i = 0 ; i < n ; i++){
        for(int j = i +1 ; j < n ; j++){
            int xorr = 0 ;
            for(int K = i ; K <= j ; K++){
                xorr = xorr^a[K];
            }
            if(xorr == k) cnt++;
        }
    }
    return cnt;

    // Better approach
    for(int i = 0 ;i < n ; i++){
        int xorr = 0 ;
        for(int j = i; j < n ; j++){
            xorr = xorr^a[j];
            if(xorr == k ) cnt++;
        }
    }
    return cnt ;

}

// Optimal Solution

int subarraysWithXorK(vector<int> a , int k ){
    int n = a.size();
    int xorr = 0 ;
    map<int, int> mpp;
    mpp[xorr]++ ;
    int cnt = 0 ;
    for(int i = 0 ; i < n ; i++){
        xorr = xorr^a[i];        
        int x = xorr ^ k;
        cnt += mpp[x];
        mpp[xorr]++;
    }
    return cnt;
}

