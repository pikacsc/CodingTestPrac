/*
Most Profit Assigning Work
We have jobs: difficulty[i] is the difficulty of the ith job, and profit[i] is the profit of the ith job.

Now we have some workers. worker[i] is the ability of the ith worker, which means that this worker can only complete a job with difficulty at most worker[i].

Every worker can be assigned at most one job, but one job can be completed multiple times.

For example, if 3 people attempt the same job that pays $1, then the total profit will be $3.  If a worker cannot complete any job, his profit is $0.

What is the most profit we can make?

https://leetcode.com/problems/most-profit-assigning-work/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) 
    {
        int ans = 0;
        vector<pair<int, int>> jobs;
        for (int i = 0; i < profit.size(); i++)
            jobs.push_back({ profit[i],difficulty[i] });
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        int i = worker.size() - 1;
        int j = profit.size() - 1;

        for (; i >= 0; i--)
        {
            while (j >= 0 && jobs[j].second > worker[i])
                j--;
            if (j < 0)
                break;
            ans += jobs[j].first;
        }

        return ans;
    }
};


int main()
{
    Solution sol;
    vector<int> difficulty = { 2,4,6,8,10 };
    vector<int> profit = { 10,20,30,40,50 };
    vector<int> worker = { 4,5,6,7 };

    cout << sol.maxProfitAssignment(difficulty, profit, worker);

    return 0;
}