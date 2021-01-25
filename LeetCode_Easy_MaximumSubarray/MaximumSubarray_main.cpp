/*
https://leetcode.com/problems/maximum-subarray/

Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.


Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [0]
Output: 0
Example 4:

Input: nums = [-1]
Output: -1
Example 5:

Input: nums = [-100000]
Output: -100000


Constraints:

1 <= nums.length <= 3 * 104
-105 <= nums[i] <= 105


*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int maxsofar = nums[0];
        int curmax = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            curmax = max(nums[i], curmax + nums[i]);
            maxsofar = max(maxsofar, curmax);
        }
        return maxsofar;
    }
};


int main()
{

	return 0;
}