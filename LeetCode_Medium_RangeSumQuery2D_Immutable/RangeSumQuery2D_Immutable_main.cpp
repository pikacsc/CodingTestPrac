#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class NumMatrix {
    vector<vector<int>> matrix;
    int row = 0;
    int col = 0;
    bool isEmpty = false;
public:
    NumMatrix(vector<vector<int>>& mat) {

        if (!mat.empty())
        {
            row = mat.size();
            col = mat[0].size();
            matrix.resize(row, vector<int>(col));
            matrix = mat;
            for (int i = 0; i < row; i++)
            {
                for (int j = 1; j < col; j++)
                {
                    matrix[i][j] += matrix[i][j - 1];
                }
            }
        }
        else
        {
            isEmpty = true;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {


        if (isEmpty)
            return 0;

        int sum = 0;
        if (col1 == 0 and col2 < col)
        {
            for (int i = row1; i <= row2; i++)
            {
                sum += matrix[i][col2];
            }
        }
        else
        {
            for (int i = row1; i <= row2; i++)
            {
                sum += matrix[i][col2] - matrix[i][col1 - 1];
            }
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main()
{
    vector<vector<int>> matrix =
    {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    
    NumMatrix numMa(matrix);

    cout << numMa.sumRegion(2, 1, 4, 3);


	return 0;
}