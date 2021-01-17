/*
Count Servers that Communicate
You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. 
Two servers are said to communicate if they are on the same row or on the same column.


*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, int& res)
    {
        res += 1;
        grid[row][col] = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            if (grid[i][col] == 1)
                dfs(grid, i, col, res);
        }

        for (int i = 0; i < grid[row].size(); i++)
        {
            if (grid[row][i] == 1)
                dfs(grid, row, i, res);
        }
    }

    int countServers(vector<vector<int>>& grid) 
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                int res = 0;
                if (grid[i][j]) // checked or not
                {
                    dfs(grid, i, j, res);
                    if (res > 1)
                        ans += res;
                }
            }
        }
        return ans;
    }
};


int main()
{
    Solution sol;

    vector<vector<int>> grid =
    {
        {1, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    cout << sol.countServers(grid);

	return 0;
}