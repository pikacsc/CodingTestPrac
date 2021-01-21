/*
StoneGameII

Alice and Bob continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones.

Alice and Bob take turns, with Alice starting first.  Initially, M = 1.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

https://leetcode.com/problems/stone-game-ii/

*/

#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
public:
    int N, total;
    vector<vector<int>> dp;
    vector<int> sum;
    int dfs(int M, int i) // from i to end, what is the max [the person that takes first] can get
    {
        if (i + 2 * M >= N) return total - sum[i];
        if (dp[i][M]) return dp[i][M];

        int res = 0;
        for (int j = 1; j <= 2 * M; j++) 
        {
            res = max(res, total - sum[i] - dfs(max(j, M), i + j)); // dfs(max(j, M), i + j) is the max another person can get because he takes first
        }
        return dp[i][M] = res;
    }

    int stoneGameII(vector<int>& piles) {
        N = (int)piles.size();
        dp.resize(N, vector<int>(N, 0));
        sum.resize((size_t)N + 1, 0);
        partial_sum(piles.begin(), piles.end(), sum.begin() + 1);
        total = sum[N];
        return dfs(1,0);
    }
};

int main()
{
    vector<int> piles = { 2,7,9,4,4 };

    Solution sol;
    cout << sol.stoneGameII(piles);


	return 0;
}