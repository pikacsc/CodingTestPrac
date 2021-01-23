/*
Sort Array By Parity II
Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.

https://leetcode.com/problems/sort-array-by-parity-ii/


*/
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        vector<int> res(n);
        int evencount = 0;
        int oddcount = 1;

        for (int i = 0; i < n; i++) {
            if (A[i] % 2 == 0) {
                res[evencount] = A[i];
                evencount += 2;
            }
            else {
                res[oddcount] = A[i];
                oddcount += 2;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> a = { 4,2,5,7 };
    Solution sol;
    vector<int> output = sol.sortArrayByParityII(a);
    for (auto& l : output)
        cout << l << " ";

	return 0;
}