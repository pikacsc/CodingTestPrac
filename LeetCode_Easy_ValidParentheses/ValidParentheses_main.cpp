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

        //홀수는 무조건 false 이므로
        if (s.length() % 2 != 0)
        {
            return false;
        }


        //"()[]{}", 
        //처음으로 오는 경우 그 다음 아니면 맨 마지막이어야 함
        //즉 두번째로 오는 것은 닫는 문자여서는 안되고, 시작하는 괄호여야함

        //각각의 괄호 인덱스 기록, 없으면 -1
        stack<char> st;

        int startCurly = -1;
        int startPar = -1;
        int startSquare = -1;

        bool valid = true;

        //시작 괄호 글자 위치 판별
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


        //글자의 인덱스가 알맞은 위치에 있는지를 판별
        //바로 옆에 있던지 아니면 대칭되게 위치하던지
        //대칭 예시
        //start == 1 이면서 전체길이 6인문자열인 경우
        //0 1 2 3 4 5, 4가된다

        //start == 3 이면서 전체길이 8인문자열인 경우
        //0 1 2 3  4 5 6 7, 4가된다
        //즉 맨 마지막 index 에서 시작 위치 만큼 빼주면 된다

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
        //홀수는 무조건 false 이므로
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