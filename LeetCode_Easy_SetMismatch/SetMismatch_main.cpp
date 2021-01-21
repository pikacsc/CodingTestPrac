/*
Set Mismatch

You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

https://leetcode.com/problems/set-mismatch/

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int p = 0, q = (int)nums.size() - 1;
        for (p; p != nums.size(); ++p)
        {
            if (nums[p] != p + 1)
                break;
        }
        for (q; q != p; --q)
        {
            if (nums[q] != q + 1)
                break;
        }
        if (nums[p] == p + 2)
            return vector<int>{q + 2, p + 1};
        else
            return vector<int>{p, q + 1};
    }
};

int main()
{
    
    return 0;
}