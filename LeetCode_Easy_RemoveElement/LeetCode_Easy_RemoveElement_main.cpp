/*
27. Remove Element

https://leetcode.com/problems/remove-element/

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return std::distance(nums.begin(), std::remove(nums.begin(), nums.end(), val));
    }
};

int main()
{
    Solution sol;
    vector<int> nums{ 1 };


    std::cout << sol.removeElement(nums, 1);

    return 0;
}