/*
Remove Duplicates from Sorted Array

Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

https://leetcode.com/problems/remove-duplicates-from-sorted-array/

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define Sol_1

#ifdef Sol_1
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.empty()) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[j] != nums[i])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
#endif // Sol_1

//GuideCode - two line solution
#ifdef Sol_2
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};
#endif // Sol_1



int main()
{
    Solution sol;
    vector<int> nums = { 1,1,2 };

    for (auto& l : nums)
    {
        cout << l << " ";
    }
    cout << endl;

    sol.removeDuplicates(nums);
    for (auto& l : nums)
    {
        cout << l << " ";
    }
    cout << endl;


	return 0;
}