/*
https://leetcode.com/problems/reverse-integer/
Given a 32-bit signed integer, reverse digits of an integer.

ex1)
Input: 123
Output: 321

ex2)
Input: -123
Output: -321

ex3)
Input: 120
Output: 21

ex4)
Input: 901000
Output: 109

ex5)
Input: 1534236469 //when overflow, return 0
Output: 0
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>

#define Sol_2

#ifdef Sol_1 //incomplete
//Runtime: 4 ms
class Solution {
public:
    int reverse(int x)
    {
        std::string str = std::to_string(x);
        std::stringstream ss;
        short count = 0;
        if (x < 0)
        {
            ss.put('-');
        }
        while (str.length() != 0)
        {
            char c = *(--str.end());
            if (c != '-')
            {
                ss.put(c);
                count++;
            }
            str.pop_back();
        }

        //overflow check
        if (count >= 10)
        {
            ss.str().at(1) == std::to_string(INT32_MAX).at(1));
        }

        return atoi(ss.str().c_str());
    }
};
#endif // Sol_1

#ifdef Sol_2  //GuideSolution
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
            {
                return 0;
            }
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
            {
                return 0;
            }
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
#endif // Sol_2




int main()
{
    Solution sol;
    printf("%d", sol.reverse(1534236469));
}
