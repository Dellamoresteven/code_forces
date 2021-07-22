#include <stdlib.h>
#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    //vector<int> place_holder(n);
    //set place_holder;
    unordered_set<int> place_holder(nums.begin(), nums.end());
    for(int i = 1; i < n; ++i) {
        if(place_holder.find(i) == place_holder.end())
            return i;
    }
    return n+1;
}

int main() {
    vector<int> vec{1,4,3};
    printf("%d\n", firstMissingPositive(vec));
}
