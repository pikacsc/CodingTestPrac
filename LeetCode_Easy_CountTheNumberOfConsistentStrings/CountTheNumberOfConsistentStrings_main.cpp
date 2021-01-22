/*
Count the Number of Consistent Strings

You are given a string allowed consisting of distinct characters and an array of strings words. 
A string is consistent if all characters in the string appear in the string allowed.
Return the number of consistent strings in the array words.


https://leetcode.com/problems/count-the-number-of-consistent-strings/
*/


#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;



class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, bool> hmap;

        for (auto& l : allowed)
            hmap[l] = true;

        int noConsisCount = 0;
        for (auto& s : words)
        {
            for (auto& c : s)
            {
                if (hmap[c] == false)
                {
                    noConsisCount++;
                    break;
                }
            }
        }
        return (int)words.size() - noConsisCount;
    }
};

int main()
{
    Solution sol;

    string allowed("ab");

    vector<string> words = { "ad","bd","aaab","baa","badab" };

    cout << sol.countConsistentStrings(allowed, words);


    return 0;
}