#include <bits/stdc++.h>
using namespace std;


// Binary search Luv


int main()
{
	int n ; 
	cin >> n ;
	vector<int> v(n);
	for(int i = 0 ;i < n ; i++)
	{
		cin >>v[i];
	}
	int to_find ;
	cin >> to_find ;

	// Binary Search Algorithm

	int lo = 0 , hi = n-1 ;
	int mid ;
	while(hi - lo > 1){
		int mid = (hi+ lo) / 2 ;
		if(v[mid] < to_find){
			lo = mid +1 ;
		}else{
			hi = mid;
		}
	}

	if(v[lo] == to_find){
		cout << lo << endl;
	} else if( v[hi] == to_find)
	{
		cout << hi << endl;
	}

	return 0 ;

}

// TC
// log(n) 







