/*
20. Valid Parentheses
Easy

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true


Example 2:
Input: "()[]{}"
Output: true


Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true

Example 6:
Input: "[(({})}]"
Output: false

Example 7:
Input: "(([]){})"
Output: true

Example 8:
Input : ""
Output: true
*/

#define Sol_3

#ifdef Sol_1 //incomplete

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        //Ȧ���� ������ false �̹Ƿ�
        if (s.length() % 2 != 0)
        {
            return false;
        }


        //"()[]{}", 
        //ó������ ���� ��� �� ���� �ƴϸ� �� �������̾�� ��
        //�� �ι�°�� ���� ���� �ݴ� ���ڿ����� �ȵǰ�, �����ϴ� ��ȣ������

        //������ ��ȣ �ε��� ���, ������ -1
        stack<char> st;

        int startCurly = -1;
        int startPar = -1;
        int startSquare = -1;

        bool valid = true;

        //���� ��ȣ ���� ��ġ �Ǻ�
        for (int i = 0; i < s.length(); i++)
        {
            if (s.c_str()[i] == '(')
            {
                startPar = i;
            }
            else if (s.c_str()[i] == '[')
            {
                startSquare = i;
            }
            else if (s.c_str()[i] == '{')
            {
                startCurly = i;
            }
            else
            {
                continue;
            }
        }


        //������ �ε����� �˸��� ��ġ�� �ִ����� �Ǻ�
        //�ٷ� ���� �ִ��� �ƴϸ� ��Ī�ǰ� ��ġ�ϴ���
        //��Ī ����
        //start == 1 �̸鼭 ��ü���� 6�ι��ڿ��� ���
        //0 1 2 3 4 5, 4���ȴ�

        //start == 3 �̸鼭 ��ü���� 8�ι��ڿ��� ���
        //0 1 2 3  4 5 6 7, 4���ȴ�
        //�� �� ������ index ���� ���� ��ġ ��ŭ ���ָ� �ȴ�

        char c1 = *(s.rbegin() + startCurly);
        char c2 = *(s.rbegin() + startSquare);
        //char c3 = *(s.rbegin() + startPar);
        if (startCurly >= 0)
        {
            if (s.c_str()[startCurly + 1] != '}' &&  *(s.rbegin() + startCurly) != '}')
            {
                valid = false;
            }
        }
        if (startSquare >= 0)
        {
            if (s.c_str()[startSquare + 1] != ']' && *(s.rbegin() + -startSquare) != ']')
            {
                valid = false;
            }
        }
        if (startPar >= 0)
        {
            if (s.c_str()[startPar + 1] != ')' && *(s.rbegin() + startPar) != ')' )
            {
                valid = false;
            }
        }

        return valid;
    }
};

#endif // Sol_1


#ifdef Sol_2 //incomplete

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    char GetOppositeChar(char _c)
    {
        switch (_c)
        {
        case '(':
            return ')';
        case '[':
            return ']';
        case '{':
            return '}';
        default:
            return '\0';
        }
    }

    bool isValid(string s) {

        size_t length = s.length();
        //Ȧ���� ������ false �̹Ƿ�
        if (length % 2 != 0)
        {
            return false;
        }
        
        
        if (length == 0)
        {
            return true;
        }

        sort(s.begin(), s.end());


        int curly = 0; // {
        int par = 0; // (
        int square = 0; // [
        char c = 0;
        size_t i = 0;
        while (s.begin() + i != s.end())
        {
            c = *(s.begin() + i);
            if (c == '(')
            {
                par++;
            }
            else if (c == '[')
            {
                square++;
            }
            else if (c == '{')
            {
                curly++;
            }
            else if (c == ')')
            {
                par--;
            }
            else if (c == ']')
            {
                square--;
            }
            else if (c == '}')
            {
                curly--;
            }
            i++;
        }
        
        return (curly == 0) && (par == 0) && (square == 0);
    }
};

#endif // Sol_2


#ifdef Sol_3 // Guide Code

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        if (s.length() == 0) {
            return true;
        }
        if (s.length() == 1) {
            return false;
        }

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            cout << c;
            if (c == '}' || c == ')' || c == ']') {
                if (stack.size() == 0) return false;
                if (c == '}' && stack.top() != '{') return false;
                if (c == ')' && stack.top() != '(') return false;
                if (c == ']' && stack.top() != '[') return false;
                stack.pop();

            }
            else {
                stack.push(c);
            }
        }
        cout << "reached end";
        if (stack.size() == 0) return true;
        return false;
    }
};

#endif // Sol_3

int main()
{
    Solution sol;
    printf("%d", sol.isValid("([)]"));

    return 0;
}