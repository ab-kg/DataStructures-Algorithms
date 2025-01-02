#include<bits/stdc++.h>
using namespace std;

int main()
{
    // vector<int> v = {1 , 2 , 3 , 4 , 5  } ;
    // for(int i = 0 ; i < v.size() ; ++i)
    // {
    //     cout << v[i] << " " << endl;
    // }
    // cout << endl ;
    // // iterator is just the pointer like things to containers
    // vector<int> ::iterator it = v.begin();
    // for(it = v.begin() ; it != v.end() ; ++it){
    //     cout << (*it) << endl;
    // }
    // // cout << (*(it)) << endl;

    vector<int> v = { 2 , 3 , 4 , 5 , 6 , 8 };
    for(int i = 0 ;i  < v.size() ; i++){
        cout << v[i] << " " ;
    }
    
    cout << endl;
    vector<pair<int , int>> v_p = { { 1, 2 } , { 2 , 3} , { 3 , 4} , { 4 , 5} };
    vector<pair<int , int>> ::iterator it ;

    for(it = v_p.begin() ; it != v_p.end() ; ++it)
    {
        cout << (*it).first << (*it).second << endl;
    }

    // actual values are brought here 
    for(int &value : v)
    {
        cout << value++ << " " ; 
    }

    for(pair<int, int> &value : v_p){
        cout << value.first << " " << value.second << endl;
    }

    for(auto &value : v_p){
        cout << value.first << value.second << endl;
    }

    // copies of values are here 
    for(auto value : v )
    {   
        value++ ;
        cout << value << " " ;
    }

}

