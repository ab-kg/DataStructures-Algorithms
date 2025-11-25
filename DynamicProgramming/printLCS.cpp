// lcs = longest common subsequene 

#include <bits/stdc++.h> 
using namespace std ; 

void lcs(string s1 , string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));

    for(int i = 0 ; i<= n ;i++)
    {
        dp[i][0] = 0 ;
    }

    for(int j = 0 ; j <=  m ; j++ )
    {
        dp[0][j] = 0 ; 
    }

    for(int i1 = 1 ; i1 <= n ; i1++)    
    {
        for(int i2 = 1 ; i2 <= m ; i2++)
        {
            if(s1[i1 -1 ] == s2[i2 - 1])
                dp[i1][i2] = 1 + dp[i1 - 1][i2 -1 ];
            else 
                dp[i1][i2] = 0 + max(dp[i1-1][i2] , dp[i1][i2-1]);
        }
    }

    int len = dp[n][m];
    int i  = n ; 
    int j = m ; 

    int index = len - 1 ; 
    string str = "";
    for(int i = 1 ; i <= len ; i++)
        str += "$";

    while(i > 0 && j >0 )
    {
        if(s1[i-1] == s1[j-1])
        {
            str[index] = s1[i-1];
            index--;
            i--;
            j--;
        }
        else if( s1[i-1] > s2[j-1])
        {
            i--;
        }else 
        {
            j-- ;
        }
    }


    

}


