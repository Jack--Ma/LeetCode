//
//  WordBreak.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/4.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "WordBreak.hpp"

/**
 Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

 Note that the same word in the dictionary may be reused multiple times in the segmentation.
 
 Input: s = "leetcode", wordDict = ["leet","code"]
 Output: true
 Explanation: Return true because "leetcode" can be segmented as "leet code".
 
 Input: s = "applepenapple", wordDict = ["apple","pen"]
 Output: true
 Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
 Note that you are allowed to reuse a dictionary word.
 
 Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 Output: false
 */

void testWordBreak() {
    /**
     "ccbb"
     ["bc","cb"]
     "cars"
     ["car","ca","rs"]
     */
    string s = "catsandog";
    vector<string> wordDict = {"cats","dog","sand","and","cat"};
    cout << Solution().wordBreak(s, wordDict) << endl;
}

/// solution by use recursion
/// Time complexity is O(2^n). Time Limit Exceeded
bool _wordBreak_recursion(string s, vector<string> &wordDict) {
    if (s.empty()) {
        return true;
    }
    int size = (int)wordDict.size();
    for (int j = 0; j < size; j++)  {
        string word = wordDict[j];
        int start = (int)s.find(word);
        if (start == 0) {
            // find wordBreak in next s
            string next_s = string(s).erase(start, word.length());
            if (_wordBreak_recursion(next_s, wordDict)) {
                return true;
            }
        }
    }
    return false;
}

/// solution by use DP
bool _wordBreak_DP(string s, vector<string> &wordDict) {
    /**
     The DP[i] mean the substr which range is [0,i] of s, fits wordDict or not
     Eg. s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
     And. DP = [1,0,0,1,1,0,0,1,0,0]
     
     DP[1] = (find s[0,0] in wordDict) && DP[0]
     DP[2] = (find s[0,1] in wordDict) && DP[0] || (find s[1,1] in wordDict) && DP[1]
     ...
     DP[n] = (find s[0,n] in wordDict) && DP[0] || ... ||
             (find s[n-1,n] in wordDict) && DP[n-1]
     */
    int n = (int)s.size();
    vector<bool> DP(n+1);
    DP[0] = true;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < i; j++) {
            // in every loop, substr range is [j,i]
            string subStr = s.substr(j, i-j);
            auto _find = find(wordDict.begin(), wordDict.end(), subStr);
            if (DP[j] && _find != wordDict.end()) {
                DP[i] = true;
                break;
            }
        }
    }
    
    return DP[n];
}

/// solution by DP after optimize
bool _wordBreak_DP2(string s, vector<string> &wordDict) {
    size_t n = s.size();
    vector<int> DP(n+1, 0);
    DP[0] = 1;
    for (int index = 0; index < n; ++index) {
        if (DP[index] == 1) {
            for (auto word: wordDict) {
                if (s.find(word, index) == index) {
                    DP[index + word.size()] = 1;
                }
                if (DP[n]) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Solution::wordBreak(string s, vector<string> &wordDict) {
    return _wordBreak_DP2(s, wordDict);
}
