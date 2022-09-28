#include <vector>
#include <iostream>

using namespace std;

// for displaying vector while debugging
ostream &operator<<(ostream &os, const vector<int> &vector)
{
    for (int element : vector)
    {
        os << element << " |";
    }
    return os;
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int idx1 = m - 1, idx2 = n - 1;
    int idx = m + n - 1;

    while (idx1 >= 0 && idx2 >= 0)
    {
        cout << "idx1: " << idx1 << "\tidx2: " << idx2 << "\nidx: " << idx << "\nnums1: " << nums1 << "\nnums2: " << nums2 << "\n\n";

        if (nums1.at(idx1) >= nums2.at(idx2))
        {
            nums1.at(idx) = nums1.at(idx1);
            idx1--;
        }

        else
        {
            nums1.at(idx) = nums2.at(idx2);
            idx2--;
        }
        idx--;
    }

    while (idx >= 0 && idx2 >= 0)
    {
        nums1.at(idx--) = nums2.at(idx2--);
    }
}