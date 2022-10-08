#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    unordered_map<int, int> tracker;
    for (int i : nums)
    {
        if (tracker[i] == 1) return true;
        
        else tracker[i] = 1;
        
    }
    return false;
}