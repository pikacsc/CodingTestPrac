/*

Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, 
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Input: grid = 
  [
   [1,3,1],
   [1,5,1],
   [4,2,1]
  ]
Output: 7
Explanation: Because the path 1 ¡æ 3 ¡æ 1 ¡æ 1 ¡æ 1 minimizes the sum.



Input: grid = [[1,2,3],[4,5,6]]
Output: 12


m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size()));
        dp[0][0] = 0;
        for (int i = 0, j = 1; i < (int)dp.size(); i++)
        {
            if (i == 0)
            {
                while (j < (int)dp[i].size())
                {
                    dp[i][j] = dp[i][j - 1] + grid[i][j - 1];
                    j++;
                }
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + grid[i - 1][j];
                j++;
                for (j = 1; j < (int)dp[i].size(); j++)
                {
                    dp[i][j] = min(dp[i - 1][j] + grid[i - 1][j], dp[i][j - 1] + grid[i][j - 1]);
                }
            }
            j = 0;
        }
        return grid[grid.size() - 1][grid[0].size() - 1] + dp[dp.size() - 1][dp[0].size() - 1];
    }
};


int main()
{
    vector<vector<int>> grid =
    {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1},
    };

    Solution sol;

    cout << sol.minPathSum(grid);


	return 0;
}