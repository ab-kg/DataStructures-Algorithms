#include  <iostream>
#include <bits/stdc++.h>

using namespace std;

    int binaryGap(int n) {
        string s ;
        while(n != 0 )
        {
            int add = n %2 ;
            char ch = '0' + add;
            s+= ch ;
            n = n/2;
        }
        // reverse(s.begin() , s.end());

        int maxi = 0 ;
        int count  = -1 ;
        int t = 0;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == '1')
            {     
                t++;
                if(count != -1){
                    
                    maxi = max(maxi , count);
                }
                count = 1 ;
            }else if(count != -1) {
                count++;
            }
        }
        return  (t >= 2 ) ? maxi : 0 ;
}


int main()
{
    int num = binaryGap(5);
    cout << num << endl;
    std::cin.get();
}