/*
https://leetcode.com/problems/word-break/

Word Break

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        for (int j = 0; j < wordDict.size(); j++) {
            size_t pos = s.find(wordDict[j], 0);
            if (pos != string::npos && pos == 0) {
                dp[wordDict[j].size() - 1] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            if (dp[i]) {
                for (int j = 0; j < wordDict.size(); j++) {
                    size_t pos = s.find(wordDict[j], i + 1);
                    if (pos != string::npos && pos == i + 1) {
                        if (i + wordDict[j].size() == n - 1) return true;
                        dp[i + wordDict[j].size()] = true;
                    }
                }
            }
        }
        return dp[n - 1];
    }
};


int main()
{
    Solution sol;

    vector<string> wordDic =
    {
        string("apple"),
        string("pen"),
    };

    cout << sol.wordBreak(string("applepenapple"), wordDic);



    return 0;
}