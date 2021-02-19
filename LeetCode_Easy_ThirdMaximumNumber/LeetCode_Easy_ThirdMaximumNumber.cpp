/*
https://leetcode.com/problems/third-maximum-number/

Given integer array nums, return the third maximum number in this array. 
If the third maximum does not exist, return the maximum number.



Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation: The third maximum is 1.
Example 2:

Input: nums = [1,2]
Output: 2
Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:

Input: nums = [2,2,3,1]
Output: 1
Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.


Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1

*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        std::priority_queue<int, vector<int>, std::less<>> pq;
        std::unordered_map<int, bool> hmap;

        for (auto& l : nums)
        {
            if (hmap[l] == false)
            {
                pq.push(l);
                hmap[l] = true;
            }
        }

        if (pq.size() > 2)
        {
            pq.pop();
            pq.pop();
        }

        return pq.top();
    }
};


int main()
{
    Solution sol;
    vector<int> nums = { 3, 2, 1 };
    std::cout << sol.thirdMax(nums);

	return 0;
}