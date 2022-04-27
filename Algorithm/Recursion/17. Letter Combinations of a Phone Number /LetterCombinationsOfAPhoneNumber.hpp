//
//  LetterCombinationsOfAPhoneNumber.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/27.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef LetterCombinationsOfAPhoneNumber_hpp
#define LetterCombinationsOfAPhoneNumber_hpp

#include <stdio.h>

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution17 {
private:
    string digits;
    unordered_map<char, vector<char>> digitMap;
    
    void _letterCombinations(string sub, int index);
    
public:
    vector<string> result;
    
    vector<string> letterCombinations(string digits);
};

void testLetterCombinationsOfAPhoneNumber();

#endif /* LetterCombinationsOfAPhoneNumber_hpp */
