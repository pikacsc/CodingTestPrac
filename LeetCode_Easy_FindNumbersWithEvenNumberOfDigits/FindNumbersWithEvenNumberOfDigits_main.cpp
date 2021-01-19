/*
Find Numbers with Even Number of Digits

https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        string s;
        for (int i = 0; i < nums.size(); i++)
        {
            s = to_string(nums[i]);
            if (s.length() % 2 == 0)
                count++;
        }
        return count;
    }
};


int main()
{
    vector<int> nums = { 12,345,2,6,7896 };
    Solution sol;
    cout << sol.findNumbers(nums);

	return 0;
}