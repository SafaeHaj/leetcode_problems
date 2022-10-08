#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<char> slicer(vector<char> &vect, int idx1, int idx2) {
    
    vector<char> result;
    result.reserve(idx2-idx1+1);

    result.insert(result.begin(), vect.begin() + idx1, vect.begin() + idx2 + 1);
    
    return result;
} 


bool isValidSudoku(vector<vector<char>> &board)
{
    unordered_map<int, vector<char>> rows;
    unordered_map<int, vector<char>> columns;
    unordered_map<int, vector<char>> grids;

    rows.reserve(9);
    columns.reserve(9);
    grids.reserve(9);

    for (int i = 0; i < 9; i++)
    {
        // row values
        rows[i] = board[i];
        columns[i].reserve((char)9);
        for (int j = 0; j < 9; j++)
        {
            // column values
            columns[i].push_back(board[j][i]);
        }
    }

    // grid values
    int square = 0;
    for(int row = 0; row < 9; row++) {
        vector<char> r1 = slicer(rows[row],0,2);
        vector<char> r2 = slicer(rows[row],3,5);
        vector<char> r3 = slicer(rows[row],6,8);

        grids[square].insert(grids[square].begin(), r1.begin(), r1.end());
        grids[square+1].insert(grids[square+1].begin(), r2.begin(), r2.end());
        grids[square+2].insert(grids[square+2].begin(), r3.begin(), r3.end());

        if((row+1) % 3 == 0) square = square + 3;
    }

    // number verification
    unordered_map<char,int> tracker;
    
    for(int i = 0; i < 9 ; i++) {

        for(char num: rows.at(i)) {
            if(tracker[num] == 1 && num != '.') return false;
            else tracker[num] = 1;
        }

        for(char num: columns.at(i)) {
            if(tracker[num] == 2 && num != '.') return false;
            else tracker[num] = 2;
        }

        for(char num: grids.at(i)) {
            if(tracker[num] == 3 && num != '.') return false;
            else tracker[num] = 3;
        }

        tracker.clear();
    }

    return true;
}