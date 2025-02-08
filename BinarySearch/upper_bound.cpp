#include <bits/stdc++.h>
using namespace std;

int lower_bound(vector<int>&v , int element)
{
	int low = 0 ;
	int high = v.size()-1 ;
	int mid ;
	while(low - high > 1 )
	{
		mid = (low +high)/2;
		if( v[mid] < element ) 
		{
			low = mid + 1 ;
		}
		else
		{
			high = mid ;
		}
	}
	if(v[low] >= element){
		return low ;
	}
	if(v[high] >= element){
		return high;
	}
	return -1 ;
}



int upper_bound(vector<int>&v , int element)
{
	int low = 0 ;
	int high = v.size()-1 ;
	int mid ;
	while(low - high > 1 )
	{
		mid = (low + high)/2;
		if( v[mid] <= element ) 
		{
			low = mid + 1 ;
		}
		else
		{
			high = mid ;
		}
	}
	if(v[low] > element){
		return low ;
	}
	if(v[high] > element){
		return high;
	}
	return -1 ;
}




int main(){
	int n ;
	cin >>n ;
	vector<int> v(n);
	for(int i = 0 ;i < n ; i++){
		cin >> v[i];
	}
	int element ;
	cin >> element ;
	int lb = lower_bound(v , element);
	cout << lb << " " << (lb != -1 ? v[lb] : -1 ) << endl;
	int ub = upper_bound(v , element);
	cout << ub << " " << (ub != -1 ? v[ub] : -1) << endl;

}