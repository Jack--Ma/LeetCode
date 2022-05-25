//
//  FindSmallestLetterGreaterThanTarget.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/24.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "FindSmallestLetterGreaterThanTarget.hpp"

/**
 Given a characters array letters that is sorted in non-decreasing order and a character target, return the smallest character in the array that is larger than target.
 
 Input: letters = ["c","f","j"], target = "a"
 Output: "c"
 
 Input: letters = ["c","f","j"], target = "c"
 Output: "f"
 */

void testFindSmallestLetterGreaterThanTarget() {
    vector<char> letters = {'c','c','d','f','j'};
    cout << Solution().nextGreatestLetter(letters, 'z') << endl;
}

char Solution::nextGreatestLetter(vector<char> &letters, char target) {
    int size = (int)letters.size();
    int left = 0, right = size-1;
    // char 'z' is equal to int 122
    char result = (char)123;
    while (left <= right) {
        int p = (left + right) / 2;
        char letter = letters[p];
        if (letter > target) {
            right = p-1;
            result = letter < result ? letter : result;
        } else {
            left = p+1;
        }
    }
    
    if (result == 123) {
        return letters[0];
    }
    return result;
}
