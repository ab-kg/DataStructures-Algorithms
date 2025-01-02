#include<bits/stdc++.h>
using namespace std;

vector<int> nums ;
vector<vector<int>> subsets ;

void generate(vector<int> &subset , int i  , vector<int> &nums ){

    if(i == nums.size()) {
        subsets.push_back(subset);
        return ;
    }

    // ith element not in subset
    generate(subset , i+1 , nums);

    // ith element in subset
    subset.push_back(nums[i]);
    generate(subset , i+1 , nums);
    subset.pop_back();
}

int main(){

}
