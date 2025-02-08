#include <bits/stdc++.h>
using namespace std;

// Montonic Arrays 

// Predicate Function ( Hard Questions )
// Ex: F F F F F T T T T , T T T F F F 

// Binary Search can be applied on monotonic series 

// Sorted Array ( Montonic Array )
// Search Space in the array 

int binarySearch(vector<int> &nums , int target)
{
    int n = nums.size();
    // defining search space 
    int left = 0 ;
    int right = n-1 ;
    while(left <= right)
    {
        int mid = left + (right - left)/2 ;
        if(nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
}


// time complexity here is 
// 2^x = n 
// x = logn  (base 2)

int main()
{
    vector<int> a = { 3 , 4 ,5 , 6, 7 , 8 , 9};
    int target = 6;
    int ind = binarySearch(a , target);
    if(ind == -1) cout << "The target is not present" << endl;
    else cout << "The target is at the index: "<< ind << endl;
    return 0 ;
}


