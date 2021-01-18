/*
Best Sightseeing Pair
Given an array A of positive integers, A[i] represents the value of the i-th sightseeing spot, 

and two sightseeing spots i and j have distance j - i between them.

The score of a pair (i < j) of sightseeing spots is (A[i] + A[j] + i - j) : the sum of the values of the sightseeing spots,

minus the distance between them.

Return the maximum score of a pair of sightseeing spots.

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        priority_queue<int> pq;
        pq.push(A[0]);
        int maxi = INT_MIN;
        for (int i = 1; i < A.size(); i++)
        {
            int v = pq.top();
            int c = v + A[i] - 1;
            maxi = max(maxi, c);
            pq.push(A[i] + i);
        }
        return maxi;
    }
};


int main()
{
    vector<int> a = { 8,1,5,2,6 };
    Solution sol;

    cout << sol.maxScoreSightseeingPair(a);

	return 0;
}