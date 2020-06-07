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

        //ù��° �ε��� ���� �ϳ��� ���ؼ� �ٸ��� �Ѿ�� ������ stringstream�� ����
        //1.��� str �� �� �ش�Ǵ��� ���� ã��
        //2.�� ��ġ�ϴ°� �����Ǹ� �������� ���� char�� ��

        if (strsSize > 1)
        {
            strsIndex++;
        }
        if (1 < strsSize)
        {
            //while, ���ξ� ã�� �۾�, �ϳ��� ����ġ �ϸ� �۾�����
            while (charIndex < strs[strsIndex].length())//������ �Ǵ� charIndex�� ������ ����� �ʴ´� 
            {
                if ((*(firstStr.begin() + charIndex) == *(strs[strsIndex].begin() + charIndex)))
                {
                    if (strsIndex == strs.size() - 1) // ��� str�� �� ������ ���
                    {
                        charIndex++;
                        strsIndex = 1;
                        continue;
                    }
                    else // ���� str�� �Ѿ��
                    {
                        strsIndex++;
                        continue;
                    }
                }
                else //�ٸ���, ���ξ� ã�� �۾� ����
                {
                    break;
                }

            }

            if (charIndex > 0) //ã�Ƴ����� 1���ڶ� �ִ�
            {
                for (int i = 0; i < charIndex; i++)
                {
                    ss.put(firstStr[i]); //stringstream�� ����
                }
            }
        }

        if (strsSize == 1) //str ���ڰ� �ϳ��� ������ ���
        {
            return firstStr; //�ش� ���� �״�� ����
        }
        else //stringstream�� �����س��� ���ξ� ����
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