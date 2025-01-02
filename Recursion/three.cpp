// Generate Paranthesis

#include<bits/stdc++.h>
using namespace std;

// what is backtracking ??
// pop_back function that is used here is the backtracking . 

vector<string> valid ;

// void generate(string &s , int open , int close){
//     if(open == 0 && close == 0){
//         valid.push_back(s);
//         return ;
//     }

//     if(open > 0){
//         s.push_back('(');
//         generate(s , open-1 , close);
//         s.pop_back();
//     }

//     if(close > 0  )
//     {
//         if(open < close ){
//             s.push_back(')');
//             generate(s , open , close-1);
//             s.pop_back();
//         }
//     }
// }

void generate(string s ,int open , int close )
{   
    cout << s << endl;
    if(open == 0 & close == 0){
            valid.push_back(s);
            return ;
    }

    // cout << s << endl;
    if(open > 0)
    {
        s.push_back('(');
        generate(s , open-1 , close);
        s.pop_back();
    }

    // cout << s << endl;
    if(close > 0)
    {
        if(open < close){
            s.push_back(')');
            generate(s , open , close-1);
            s.pop_back();
        }
    }
}

int main(){
    int n = 3 ;
    string s ;
    generate(s , 3 ,3 );
    for(auto ele : valid){
        cout << ele << endl;
    }
    return 90;
}
