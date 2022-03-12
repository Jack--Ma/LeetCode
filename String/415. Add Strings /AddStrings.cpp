//
//  AddStrings.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/12.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "AddStrings.hpp"

/**
 Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

 Input: num1 = "11", num2 = "123"
 Output: "134"
 */

void testAddStrings() {
    cout << Solution().addStrings("1", "9") << endl;
}

string Solution::addStrings(string num1, string num2) {
    string result;
    int i = (int)num1.size() - 1, j = (int)num2.size() - 1;
    
    int lastMod = 0;
    while (i >= 0 || j >= 0) {
        int num_1 = (i >= 0 ? num1[i] : '0') - '0';
        int num_2 = (j >= 0 ? num2[j] : '0') - '0';
        // calculate mod and remainder
        int remainder = (num_1 + num_2 + lastMod) % 10;
        lastMod = (num_1 + num_2 + lastMod) / 10;
        
        result.insert(result.begin(), ('0' + remainder));
        i--;j--;
    }
    if (lastMod != 0) {
        result.insert(result.begin(), ('0' + lastMod));
    }
    
    return result;
}
