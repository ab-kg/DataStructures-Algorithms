#include<bits/stdc++.h>
using namespace std;

void printVector(vector<pair<int, int>> &v)
{
    cout << "Size: " << v.size() << endl;
    for(int i = 0 ;i < v.size() ; i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }   
}


int main(){
    vector<pair<int , int >> p = {{1 , 2} , { 2 , 3} , { 3 , 4 }};
    printVector(p);

    // array of vectors
    vector<int> v[10];
     
    
}