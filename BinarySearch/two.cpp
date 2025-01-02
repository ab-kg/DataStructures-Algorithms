#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &nums , int low , int high , int target)
{   
    if(low > high ) return -1; // base case of the recursive function

    int mid = (low + high)/2 ;
    if(nums[mid] == target) return mid;
    else if( target > nums[mid] ) return binarySearch(nums , mid+1 , high , target);
    else return binarySearch(nums ,low , mid-1 , target );
    return 0 ;
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int n = sizeof(a);
    int ind = binarySearch(a , 0 ,n , target );
    if(ind == -1) cout << "the target is not present "<<endl;
    else cout << "the target is at the index: " << ind;
    return 0 ;
}
