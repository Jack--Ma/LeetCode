//
//  LongestPalindromicSubstring.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/16.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "LongestPalindromicSubstring.hpp"

/**
 Given a string s, return the longest palindromic substring in s.
 
 Input: s = "babad"
 Output: "bab"
 Explanation: "aba" is also a valid answer.
 */

void testLongestPalindromeSubstring() {
    cout << Solution().longestPalindromeSubstring("babad") << endl;
}

// time out solution by use recursion
static inline string _findLongestPalindromeSubstring(string s, bool isLeft, bool isRight) {
    int i = 0, j = (int)s.length() - 1;
    bool isPalindrome = true;
    while (i <= j) {
        if (s[i] == s[j]) {
            i++;
            j--;
        } else {
            isPalindrome = false;
            break;
        }
    }
    
    if (isPalindrome) {
        return s;
    } else {
        if (isLeft) {
            return _findLongestPalindromeSubstring(s.substr(0, s.length()-1), 1, 0);
        } else if (isRight) {
            return _findLongestPalindromeSubstring(s.substr(1, s.length()-1), 0, 1);
        } else {
            string left = _findLongestPalindromeSubstring(s.substr(0, s.length()-1), 1, 0);
            if (left.length() == s.length() - 1) {
                return left;
            }
            string right = _findLongestPalindromeSubstring(s.substr(1, s.length()-1), 0, 1);
            if (right.length() == s.length() - 1) {
                return right;
            }
            string mid = _findLongestPalindromeSubstring(s.substr(1, s.length()-2), 0, 0);
            if (mid.length() == s.length() - 2) {
                return mid;
            }
            return (left.length() > mid.length()) ? (left.length() > right.length() ? left : right) : (mid.length() > right.length() ? mid : right);
        }
    }
}

/**
 Better solution by use dynamic programming
 
 1st. build a 2-dimensional DP include 0 or 1, DP[i][j] mean s[i]~s[j] sub string is palindrome or not
 2rd.
    DP[i][i] = 1, mean s[i] = s[i]
    DP[i][i+1] = (s[i]==s[j]), mean two neighboring character
    DP[i][j] = (DP[i+1][j-1]) && (s[i]==s[j])
 3rd.
 */
string _longestPalindromeSubstring_DP(string s) {
    const int N = (int)s.length();
    bool DP[1000][1000] = {false};
    // use vector will consume more time and memory
//    vector<vector<bool>> DP(N, vector<bool>(N, false));
    
    int start = 0, len = 1;
    for (int i = 0; i < N; i++) {
        DP[i][i] = true;
    }
    for (int i = 0; i < N-1; i++) {
        DP[i][i+1] = (s[i] == s[i+1]);
        if (DP[i][i+1]) {
            start = i;
            len = 2;
        }
    }
    
    /**
     current DP
        b a b a d
     b  1 0 1 4 6
     a    1 0 2 5
     b      1 0 3
     a        1 0
     d          1
     */
    
    // calculate DP[i][j] diagonal, from 1~6
    for (int l = 2; l < N; l++) {
        for (int i = 0; i < (N-l); i++) {
            int j = i+l;
            DP[i][j] = DP[i+1][j-1] && (s[i]==s[j]);
            if (DP[i][j]) {
                start = i;
                len = j - i + 1;
            }
        }
    }
    
    string result = s.substr(start, len);
    
    return result;
}

// better solution by use manacher algorithm
string _longestPalindromeSubstring_manacher(string s) {
    
    string t(s.length()*2+1, '#');
    for (int i = 0; i < s.length(); i++) {
        t[i*2+1] = s[i];
    }
    
    // TODO: manacher
    
    int start = 0, len = 1;
    
    return s.substr(start, len);
}

string Solution::longestPalindromeSubstring(string s)  {
    return _longestPalindromeSubstring_manacher(s);
}
