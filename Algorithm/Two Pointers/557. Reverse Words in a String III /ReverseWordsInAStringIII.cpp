//
//  ReverseWordsInAStringIII.cpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/4/7.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "ReverseWordsInAStringIII.hpp"

/**
 Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
 
 Input: s = "Let's take LeetCode contest"
 Output: "s'teL ekat edoCteeL tsetnoc"
 
 Input: s = "God Ding"
 Output: "doG gniD"
 */

void testReverseWordsInAStringIII() {
    cout << Solution().reverseWordsInAStringIII("Let's take LeetCode contest") << endl;
}

string Solution::reverseWordsInAStringIII(string s) {
    s.push_back(' ');
    const int length = (int)s.length();
    int fast = 0, slow = 0;
    string result;
    while (fast < length) {
        // find space char, descending order traverse
        if (s[fast] == ' ') {
            string rs;
            for (int i = fast - 1; i >= slow; i--) {
                rs.push_back(s[i]);
            }
            rs.push_back(' ');
            result.append(rs);
            slow = fast + 1;
        }
        fast++;
    }
    result.erase(result.end()-1);
    return result;
}
