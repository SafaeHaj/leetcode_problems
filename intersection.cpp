#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> inter;

    // hashmap taking in values of smallest array of the two and their count
    unordered_map<int, int> intermap;

    // check which array is smallest and take it as starting lead
    if (nums1.size() <= nums2.size())
    {
        for (int i = 0; i < nums1.size(); i++)
        {
            intermap[nums1.at(i)]++;
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            if (intermap[nums2.at(i)] > 0 && count(inter.begin(), inter.end(), nums2.at(i)) < intermap[nums2.at(i)])
            {
                inter.push_back(nums2.at(i));
            }
        }
    }

    else
    {
        for (int i = 0; i < nums2.size(); i++)
        {
            intermap[nums2.at(i)]++;
        }

        for (int i = 0; i < nums1.size(); i++)
        {
            if (intermap[nums1.at(i)] > 0 && count(inter.begin(), inter.end(), nums1.at(i)) < intermap[nums1.at(i)])
            {
                inter.push_back(nums1.at(i));
            }
        }
    }

    return inter;
}