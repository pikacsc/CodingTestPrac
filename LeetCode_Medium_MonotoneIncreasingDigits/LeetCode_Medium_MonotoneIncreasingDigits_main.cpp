/*
Monotone Increasing Digits
Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.

(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

https://leetcode.com/problems/monotone-increasing-digits/
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string number = to_string(N);
        int firstUnmatch = -1;
        for (int i = number.length() - 1; i > 0; i--)
        {
            if (number[i] < number[i - 1])
            {
                firstUnmatch = i - 1;
                number[i - 1]--;
            }
        }

        if (firstUnmatch == -1)
            return N;
        for (int i = firstUnmatch + 1; i < number.size(); i++)
            number[i] = '9';
        int n = stoi(number);
        return n;
    }
};


int main()
{

	return 0;
}