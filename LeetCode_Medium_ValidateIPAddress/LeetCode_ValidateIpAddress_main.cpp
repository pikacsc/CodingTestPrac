/*
468. Validate IP Address
https://leetcode.com/problems/validate-ip-address/

Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

Note: You may assume there is no extra space or special characters in the input string.


Input : "2001:0db8:85a3:0:0:8A2E:0370:7334"
Output : IPv6


Input : "2001:0db8:85a3:0:0:8A2E:0370:7334:"
Output : "Neither"

Input :"1e1.4.5.6"
Output : "Neither"

Input : "256.256.256.256"
Output : "Neither"

Input : "1.0.1."
Output : Neither

Input : "12..33.4"
Output : Neither

Input : "2001:0db8:85a3:0:0:8A2E:0370:73341"
Output : "Neither"

Input "20EE:FGb8:85a3:0:0:8A2E:0370:7334"
Output : "Neither
*/
#define Sol_1

#define _CRT_SECURE_NO_WARNINGS

#ifdef Sol_1

/*
Success
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Validate IP Address.
Memory Usage: 6.2 MB, less than 92.27% of C++ online submissions for Validate IP Address.

Accepted: 73,940
Submissions: 309,559
*/
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool IsValidInteger(char *_str)
    {
        if (atoi(_str) > 255)
        {
            return false;
        }

        if (_str[0] == '0' && strlen(_str) > 1)
        {
            return false;
        }

        for (int i = 0; i < strlen(_str); i++)
        {
            char c = _str[i];
            if (c >= '0' && c <= '9')
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    bool IsValidHexadecimal(char* _str)
    {
        if (_str[0] == '0' && strlen(_str) > 4 )
        {
            return false;
        }

        if (strlen(_str) > 4)
        {
            return false;
        }

        for (int i = 0; i < strlen(_str); i++)
        {
            char c = _str[i];
            bool InValidtest1 = c < '0' || c > '9';

            if (InValidtest1)
            {
                bool InValidtest2 = (c < 'a' || c > 'f'); // c가 'a' 보다 작거나, 'f' 보다 크다
                bool InValidtest3 = (c < 'A' || c > 'F'); // c가 'A' 보다 작거나, 'F' 보다 크다
                if (InValidtest2 && InValidtest3)
                {
                    return false;
                }
            }

        }
        return true;
    }

    string validIPAddress(string IP) {
        
        bool validIPv4 = true;
        bool validIPv6 = true;

      
        //1.IPv4 모양인지 아니면 IPv6 모양인지 검사
        //최대 갯수 넘어가는지 검사
        if (IP.length() > 15 || IP.length() < 7)
        {
            validIPv4 = false;
        }

        if (IP.length() > 39 || IP.length() < 15)
        {
            validIPv6 = false;
            if (!validIPv4)
            {
                return "Neither";
            }
        }

        // . 갯수 검사
        size_t tokenCount = 0;
        for (size_t i = 0; i < IP.length(); i++)
        {
            if (IP.c_str()[i] == '.')
            {
                tokenCount++;
            }
        }
        if (tokenCount != 3)
        {
            validIPv4 = false;
        }


        // : 갯수 검사
        tokenCount = 0;
        for (size_t i = 0; i < IP.length(); i++)
        {
            if (IP.c_str()[i] == ':')
            {
                tokenCount++;
            }
        }
        if (tokenCount != 7)
        {
            validIPv6 = false;
        }

        // 토막 갯수 검사 XXX.
        int chunkCount = 0;
        if (validIPv4)
        {
            char IPv4[16] = { 0 };
            strcpy(IPv4, IP.c_str());
            char* tok = strtok(IPv4, ".");
            chunkCount++;
            while (tok != nullptr)
            {
                if (IsValidInteger(tok) == false)
                {
                    validIPv4 = false;
                    break;
                }
                else
                {
                    tok = strtok(NULL, ".");
                    if (tok)
                    {
                        chunkCount++;
                    }
                }
            }
            if (chunkCount != 4)
            {
                validIPv4 = false;
            }
        }
        else if (validIPv6)
        {
            char IPv6[40] = { 0 };
            strcpy(IPv6, IP.c_str());
            int chunkCount = 0;
            char* tok = strtok(IPv6, ":");
            chunkCount++;
            while (tok != nullptr)
            {
                if (IsValidHexadecimal(tok) == false)
                {
                    validIPv6 = false;
                    break;
                }
                else
                {         
                    tok = strtok(NULL, ":");
                    if (tok)
                    {
                        chunkCount++;
                    }
                }
            }
            if (chunkCount != 8)
            {
                validIPv6 = false;
            }
        }

        if (validIPv4)
        {
            return "IPv4";
        }
        else if (validIPv6)
        {
            return "IPv6";
        }
        else
        {
            return "Neither";
        }
    }
};

#endif // Sol_1


int main()
{
    Solution sol;
    cout << sol.validIPAddress("20EE:FGb8:85a3:0:0:8A2E:0370:7334");

    return 0;
}