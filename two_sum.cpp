#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> keep;
    vector<int> sol;

    for (int i = 0; i < nums.size(); i++)
    {
        if (keep.count(target - nums.at(i)) == 1)
        {
            if (keep.at(target - nums.at(i)) != i)
            {
                sol = {i, keep[target - nums.at(i)]};
                break;
            }
        }

        else
            keep[nums.at(i)] = i;
    }

    return sol;
}
