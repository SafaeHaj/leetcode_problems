#include <iostream>
#include <vector>

using namespace std;

// used Kadane's Algorithm
int maxSubArray(vector<int> &nums)
{
    int max = nums.at(0);
    int max_end = 0;

    for (int elem : nums)
    {
        max_end += elem;
        
        if (max < max_end) max = max_end;

        if (max_end < 0) max_end = 0;
    }

    return max;
}