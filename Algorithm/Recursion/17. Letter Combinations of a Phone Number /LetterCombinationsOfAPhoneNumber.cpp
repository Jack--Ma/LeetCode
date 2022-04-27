//
//  LetterCombinationsOfAPhoneNumber.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/27.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "LetterCombinationsOfAPhoneNumber.hpp"

/**
 Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
 
 A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 
 Input: digits = "23"
 Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 */

void testLetterCombinationsOfAPhoneNumber() {
    printVector(Solution17().letterCombinations("23"));
}

void Solution17::_letterCombinations(string sub, int index) {
    for (int i = index; i < digits.length(); i++) {
        char digit = digits[i];
        vector<char> letters = digitMap[digit];
        for (int j = 0; j < letters.size(); j++) {
            char letter = letters[j];
            sub.push_back(letter);
            if (sub.length() == digits.length()) {
                // find last letter
                result.push_back(sub);
            } else {
                // enter next loop
                _letterCombinations(sub, i+1);
            }
            // revert original scene
            sub.pop_back();
        }
    }
}

vector<string> Solution17::letterCombinations(string digits) {
    this->digits = digits;
    
    unordered_map<char, vector<char>> digitMap = {
        {'2',{'a','b','c'}},
        {'3',{'d','e','f'}},
        {'4',{'g','h','i'}},
        {'5',{'j','k','l'}},
        {'6',{'m','n','o'}},
        {'7',{'p','q','r','s'}},
        {'8',{'t','u','v'}},
        {'9',{'w','x','y','z'}},
    };
    this->digitMap = digitMap;
    _letterCombinations("", 0);
    
    return result;
}
