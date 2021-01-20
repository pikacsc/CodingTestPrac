/*
Goat Latin

A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.

If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".

Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin.

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define Solution_1

#ifdef Solution_1

class Solution {
public:
    void seperateString(vector<string>& vect, string& s)
    {
        auto begin = s.begin();
        auto end = s.end();
        string sBuffer;
        for (int i = 0; i < s.length(); i++)
        {
            char c = *(begin + i);
            if (i + 1 == (int)s.length())
            {
                sBuffer.push_back(c);
                vect.push_back(sBuffer);
                break;
            }
            else if (c == ' ')
            {
                vect.push_back(sBuffer);
                sBuffer.clear();
            }
            else
            {
                sBuffer.push_back(c);
            }
        }
    }

    void firstProcess(string& s)
    {
        char c = s.c_str()[0];
        bool flag = false;
        switch (c)
        {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            flag = true;
            break;
        default:
            flag = false;
            break;
        }

        if (flag)
        {
            s.append("ma");
        }
        else
        {
            s.erase(s.begin());
            s.push_back(c);
            s.append("ma");
        }
    }


    void secondProcess(string& s, const int& a_count)
    {
        for (int i = 0; i < a_count; i++)
            s.push_back('a');
    }
    string toGoatLatin(string s) {
        vector<string> sVect;

        //seperate string 
        seperateString(sVect, s);

        //if (a, e, i, o, u) append "ma" to the end of the word
        //else remove the first letter and append it to the end then add ma
        int a_count = 1;
        string ans;
        for (int i = 0; i < sVect.size(); i++)
        {
            firstProcess(sVect[i]);
            //add a and graudally add it in each word
            secondProcess(sVect[i], a_count++);
            ans.append(sVect[i]);
            if (i + 1 != (int)sVect.size())
                ans.push_back(' ');
        }
        return ans;
    }
};
#else
class Solution {
public:
    string toGoatLatin(string s) {
    unordered_set<char> vowel({ 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' });
    stringstream ss(s);
    string str, word, suffix;
    while (ss >> word)
    {
        suffix = suffix + 'a';
        if (vowel.find(word[0]) == vowel.end())
            word = word.substr(1) + word[0];
        str = str + word + "ma" + suffix + " ";
    }
    str.pop_back();
    return str;
    }
    }
#endif // Solution_1



int main()
{
    Solution sol;
    string str("I speak Goat Latin");

    cout << sol.toGoatLatin(str);


	return 0;
}