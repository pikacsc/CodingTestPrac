/*
https://leetcode.com/problems/combination-sum-iv/


Combination Sum IV


Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (target == 0) {
            return 1;
        }

        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (target >= nums[i]) {
                res += combinationSum4(nums, target - nums[i]);
            }
        }
        return res;
    }
};


int main()
{
    vector<int> nums = { 1, 2, 3 };
    int target = 4;
    Solution sol;

    cout << sol.combinationSum4(nums, 4);



	return 0;
}