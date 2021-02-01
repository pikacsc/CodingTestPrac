/*
https://leetcode.com/problems/counting-bits/

Given a non negative integer number num. For every numbers i in the range 0 �� i �� num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        for (int n = 1; n <= num; n++) {
            if (!(n & 1)) dp[n] = dp[n / 2]; // if even
            else dp[n] = dp[n - 1] + 1; // if odd
        }
        return dp;
    }
};



int main()
{
    Solution sol;

   
    vector<int> ans = sol.countBits(2);

    for (auto& l : ans)
        cout << l << " ";

	return 0;
}