#include <iostream>

using namespace std;

int singleNumber(vector<int>& nums) {
  
    int odd = 0;
    for (int i = 0; i < nums.size(); i++) {
        odd = odd ^ nums[i];
    }

    return odd;
}
