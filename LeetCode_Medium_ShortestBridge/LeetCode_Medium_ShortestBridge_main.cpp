/*
Shortest Bridge
https://leetcode.com/problems/shortest-bridge/

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size();
        vector<vector<bool>> visited(m, vector<bool>(m, false));
        vector<vector<int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        queue<vector<int>> q;
        bool found = false;
        //Mark the first island in visited matrix using dfs
        for (int i = 0; i < m; i++) {
            if (found) {
                break;
            }
            for (int j = 0; j < m; j++) {
                if (A[i][j] == 1) {
                    dfs(A, visited, q, i, j, directions);
                    found = true;
                    break;
                }
            }
        }
        //Move steps to connect the other island using BFS, the first one is the minimum bridge
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                vector<int> vec = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int row = vec[0] + directions[i][0];
                    int col = vec[1] + directions[i][1];
                    if (row >= 0 && col >= 0 && row < m && col < m && visited[row][col] == false) {
                        if (A[row][col] == 1)
                            return step;
                        q.push({ row, col });
                        visited[row][col] = true;
                    }
                }
            }
            step++;
        }
        return -1;
    }

private:
    void dfs(vector<vector<int>>& A, vector<vector<bool>>& visited, queue<vector<int>>& q, int x, int y, vector<vector<int>>& directions) {
        if (x < 0 || x >= A.size() || y < 0 || y >= A[0].size() || visited[x][y] || A[x][y] == 0) {
            return;
        }
        visited[x][y] = true;
        q.push({ x, y });
        for (int i = 0; i < 4; i++) {
            dfs(A, visited, q, x + directions[i][0], y + directions[i][1], directions);
        }
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> A =
    {
        {0,1,0},
        {0,0,0},
        {0,0,1}
    };
    cout << sol.shortestBridge(A);


	return 0;
}