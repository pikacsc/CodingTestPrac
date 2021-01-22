/*

Rearrange Words in a Sentence

Given a sentence text (A sentence is a string of space-separated words) in the following format:

First letter is in upper case.
Each word in text are separated by a single space.
Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. If two words have the same length, arrange them in their original order.

Return the new text following the format shown above.



*/


#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string arrangeWords(string text) {
        vector<pair<int, string>> beSorted;
        map<int, string> sizeStrMap;
        string res = "";
        for (int i = 0; i < text.size(); i++) {
            string word = "";
            while (isalpha(text[i])) {
                word += tolower(text[i]);
                i++;
            }
            sizeStrMap[word.size()] += word + " ";
        }

        for (auto pair : sizeStrMap) {
            res += pair.second;
        }

        res.pop_back();
        res[0] = toupper(res[0]);
        return res;
    }
};


int main()
{
    Solution sol;

    string text("Leetcode is cool");

    cout << sol.arrangeWords(text);
}
