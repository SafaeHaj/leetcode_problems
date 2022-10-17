#include <iostream>
#include <vector>

using namespace std;

int rowFinder(vector<vector<int>> &matrix, int left, int right, int row_size, int target)
{
    int row_idx;
    while (left <= right)
    {
        row_idx = (left + right) / 2;
        if (target >= matrix[row_idx][0] && target <= matrix[row_idx][row_size])
            return row_idx;

        else if (target >= matrix[row_idx][0])
            left = row_idx + 1;
        else
            right = row_idx - 1;
    }
    return 0;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    // matrix dimensions
    const int m = matrix.size();
    const int n = matrix[0].size();

    // row of target
    const int row = rowFinder(matrix, 0, m - 1, n - 1, target);

    // low and high within row
    int low = 0, high = n - 1;

    int mid;
    do
    {
        mid = (low + high) / 2;
        if (target == matrix[row][mid] || target == matrix[row][low] || target == matrix[row][high])
            return true;

        else if (target > matrix[row][mid])
            low = mid + 1;

        else
            high = mid - 1;
    } while (low < high);

    return false;
}