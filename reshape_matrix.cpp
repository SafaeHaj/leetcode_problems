#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    vector<vector<int>> new_mat(r,vector<int>(c));
    vector<int> flat_mat(r*c);
    int m = mat.size(), n = mat[0].size(), k=0;

    if(m*n != r*c) return mat;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n ; j++){
            flat_mat.at(k++) = mat[i][j];
        }
    }
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            new_mat[i][j] = flat_mat.at(i*c+j);
        }
    }
        
        
    return new_mat;
}