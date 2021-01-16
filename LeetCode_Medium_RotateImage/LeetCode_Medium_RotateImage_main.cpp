#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void rotate(vector<vector<int>>& matrix) {
        //[00] [01] [02] [03]   
        //[10] [11] [12] [13]    
        //[20] [21] [22] [23]
        //[30] [31] [32] [33]
        int n = static_cast<int>(matrix.size());

        //transpose
        //[00] [10] [20] [30]
        //[01] [11] [21] [31]
        //[02] [12] [22] [32]
        //[03] [13] [23] [33]
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && j > i)
                {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
        }

        //reverse
        //[30] [20] [10] [00]
        //[31] [21] [11] [01]
        //[32] [22] [12] [02]
        //[33] [23] [13] [03]
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n / 2; j++) 
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = temp;
            }
        }

    }
};


void printMat(vector<vector<int>>& matrix)
{
    int n = static_cast<int>(matrix.size());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    vector<vector<int>> mat =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    printMat(mat);
    Solution sol;
    sol.rotate(mat);
    std::cout << endl;
    printMat(mat);
	return 0;
}