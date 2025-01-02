#include <bits/stdc++.h>
using namespace std;

// pascals triange

// find the value in the triangle give n and r are row and column 
// TC - O(r)
// SC - O(1)

int nCr(int n , int r ){
    long long res = 1 ;
    for(int i = 0 ;i < r ; i++){
        res = res *(n - i);
        res = res / (i + 1);
    }
    return res;
}

// r-1 C c-1 ==> gives us the value in the pascals triangle 

// print all the values of the given row 

void printRowElements(int nthrow){

    for(int c = 0 ; c <= nthrow ; c++ ){
        cout << nCr(nthrow - 1 , c-1 ) << endl;
    }

}


// ------------------------------------------
// printing the pascal's triangle

int nCr(int n , int r ){
    long long res = 1 ;
    
    for(int i =0  ;i < r ; i++){
        res = res * (n - i);
        res = res / (i + 1);
    }
    return (int)(res);
}

vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> ans;
    // store the entire pascal's traingle:
    for(int row = 1 ; row <= n ; row++){
        vector<int> tempLst;
        for(int col = 1 ; col <= row ; col++){
            tempLst.push_back(nCr(row -1 , col-1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}

vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);

    for(int col = 1 ; col < row ; col++){
        ans = ans * ( row - col);
        ans = ans / col ;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> ans;

    for(int row = 1 ; row <= n ; row++){
        ans.push_back(generateRow(row));
    }
}


