//
//  RepeatedDNASequences.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/15.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "RepeatedDNASequences.hpp"

/**
 The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

 Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.
  
 Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 Output: ["AAAAACCCCC","CCCCCAAAAA"]
 */

void testFindRepeatedDnaSequences() {
    printVector(Solution().findRepeatedDnaSequences("AAAAAAAAAAAAA"));
}

// best solution by use bit to optimize space
vector<string> Solution::findRepeatedDnaSequences(string s) {
    vector<string> result;
    // 0=0b00, 1=0b01, 2=0b10, 3=0b11
    unordered_map<char, int> dnaMap = {{'A',0},{'C',1},{'G',2},{'T',3}};
    // 10-letter will cost 2*10 bits, and can represent a sub string
    unordered_map<int, int> codeMap;
    int i = 0, code = 0;
    while (i < s.length()) {
        code = ((code << 2) | dnaMap[s[i]]);
        // 0xfffff mean 20-bits in binary, must remove higher digits beyond 20-bits
        code = code & 0xfffff;
        if (i >= 9) {
            // did appear
            if (codeMap[code] == 1) {
                result.push_back(s.substr(i - 9, 10));
            }
            codeMap[code]++;
        }
        i++;
    }
    return result;
}

// my solution
vector<string> _findRepeatedDnaSequences_my(string s) {
    if (s.size() < 10) {
        return {};
    }
    vector<string> result;
    unordered_map<string, int> subStrMap;
    
    for (int i = 0; i < s.size() - 9; i++) {
        string subStr = s.substr(i, 10);
        subStrMap[subStr]++;
    }
    
    for (auto subStr : subStrMap) {
        if (subStr.second > 1) {
            result.push_back(subStr.first);
        }
    }
    
    return result;
}
