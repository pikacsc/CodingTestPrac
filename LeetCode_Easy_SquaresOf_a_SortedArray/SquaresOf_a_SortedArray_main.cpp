/*
Squares of a Sorted Array
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
https://leetcode.com/problems/squares-of-a-sorted-array/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        for (int i = 0; i < (int)nums.size(); i++)
            ans[i] = nums[i] * nums[i];
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = { -4, -1, 0, 3, 10 };

    vector<int>ans =  sol.sortedSquares(nums);

    for (auto& l : ans)
        cout << l << " ";

    return 0;
}