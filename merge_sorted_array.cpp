#include <vector>
#include <iostream>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
    int idx1 = m-1, idx2 = n-1;
    int idx = m+n-1;
    
     while(idx1>=0 && idx2>=0) {
        if(nums1.at(idx1)>=nums2.at(idx2)) {
            nums1.at(idx) = nums1.at(idx1);
            idx1--;
        }

        else {
            nums1.at(idx) = nums2.at(idx2);
            idx2--;
        }
        idx--;
    }

    while(idx>=0 && idx2>=0) {
        nums1.at(idx--) = nums2.at(idx2--);
    }
}