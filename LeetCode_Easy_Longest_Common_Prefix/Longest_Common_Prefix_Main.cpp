/*
https://leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".


Example 1:
Input: ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Note:
All given inputs are in lowercase letters a-z.
*/

#define Sol_1


#ifdef Sol_1 
/*
Success
Runtime: 8 ms, faster than 53.01% of C++ online submissions for Longest Common Prefix.
Memory Usage: 9.2 MB, less than 52.83% of C++ online submissions for Longest Common Prefix.
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        size_t strsSize = strs.size();
        int strsIndex = 0;
        int charIndex = 0;

        if (strsSize == 0)
        {
            return "";
        }

        string firstStr = *(strs.begin());
        stringstream ss;
        //"[a]" "[b]"
        //첫번째 인덱스 부터 하나씩 비교해서 다르면 넘어가고 같으면 배열에 저장
        //1.모든 str 에 다 해당되는지 부터 찾기
        //2.다 일치하는게 입증되면 그제서야 다음 char를 비교

        if (strsSize > 1)
        {
            strsIndex++;
        }
        if (1 < strsSize)
        {
            while (charIndex < strs[strsIndex].length())//기준이 되는 charIndex가 범위를 벗어나지 않는다 
            {
                if ((*(firstStr.begin() + charIndex) == *(strs[strsIndex].begin() + charIndex)))
                {
                    if (strsIndex == strs.size() - 1) // 모든 str을 다 돌았을 경우
                    {
                        charIndex++;
                        strsIndex = 1;
                        continue;
                    }
                    else
                    {
                        strsIndex++;
                        continue;
                    }
                }
                else
                {
                    break;
                }

            }

            if (charIndex > 0)
            {
                for (int i = 0; i < charIndex; i++)
                {
                    ss.put(firstStr[i]);
                }
            }
        }
        if (strsSize == 1)
        {
            return firstStr;
        }
        else
        {
            return ss.str();
        }
    }
};
#endif // Sol_1

int main()
{
    Solution sol;
    std::vector<string> input;
 /*   input.push_back("flower");
    input.push_back("flow");
    input.push_back("flight");
 */   
    input.push_back("a");
    cout << sol.longestCommonPrefix(input);
    
    return 0;
}