#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> maam;
    
    maam.push_back({1});
    
    for(int i=1; i<numRows; i++) {
        for(int j=1; j<i+1; j++) {
            maam[i][j] = maam[i-1][j-1] + maam[i-1][j];
        }
    }

    return maam;
}
