/*
https://leetcode.com/problems/palindrome-number/

palindrome number
앞으로 읽어도 뒤로 읽어도 같은 수

ex1)
input: 121
output : true

ex2)
input: -121
output : false

*/

#include <iostream>
#include <stack>
#include <string>

#define Sol_1

#ifdef Sol_1 //Accepted, Runtime: 12 ms, Memory Usage: 6 MB

std::stack<char> myStack;

class Solution
{
	//문자열로 바꾸고, 총 갯수의 반 만큼 이동한뒤, 그수 까지의 글자들을 저장해 놨다가
		//차례차례 비교해보고 하나라도 다르면 return false
		//모두 같으면 true
public:
	bool isPalindrome(int _x)
	{
		std::string str = std::to_string(_x);
		size_t half = str.length();

		if (half % 2 == 0) // 길이가 짝수
		{
			half /= 2;

			for (size_t i = 0; i < str.length(); i++)
			{
				if (i > half - 1)
				{
					if (myStack.top() != *(str.begin() + i))
					{
						return false;
					}
					myStack.pop();
				}
				else
				{
					myStack.push(*(str.begin() + i));
				}
			}
			return true;
		}
		else //길이가 홀 수 
		{
			half /= 2;

			for (size_t i = 0; i < str.length(); i++)
			{
				if (i == half)
				{
					continue;
				}
				if (i > half)
				{
					if (myStack.top() != *(str.begin() + i))
					{
						myStack.pop();
						return false;
					}
				}
				else
				{
					myStack.push(*(str.begin() + i));
				}
			}
			return true;
		}
	}
};

#endif // Sol_1

#ifdef Sol_2 // guide code
public class Solution {
	public bool IsPalindrome(int x) {
		// Special cases:
		// As discussed above, when x < 0, x is not a palindrome.
		// Also if the last digit of the number is 0, in order to be a palindrome,
		// the first digit of the number also needs to be 0.
		// Only 0 satisfy this property.
		if (x < 0 || (x % 10 == 0 && x != 0)) {
			return false;
		}

		int revertedNumber = 0;
		while (x > revertedNumber) {
			revertedNumber = revertedNumber * 10 + x % 10;
			x /= 10;
		}

		// When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
		// For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
		// since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
		return x == revertedNumber || x == revertedNumber / 10;
	}
}
#endif // Sol_2 //


int main(void)
{
	Solution sol;
	printf("%d", sol.isPalindrome(1001));

	return 0;
}