//
//  MultiplyStrings.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/14.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "MultiplyStrings.hpp"

/**
 Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
 
 Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
 
 Input: num1 = "2", num2 = "3"
 Output: "6"
 
 Input: num1 = "123", num2 = "456"
 Output: "56088"
 */

void testMultiply() {
    cout << Solution().multiply("99", "99") << endl;
}

string Solution::multiply(string numStr1, string numStr2) {
    int size1 = (int)numStr1.size(), size2 = (int)numStr2.size();
    string result(size1 + size2, '0');
    
    int i2 = (int)numStr2.size() - 1;
    while (i2 >= 0) {
        int num2 = (numStr2[i2] - '0');
        
        int carryNum = 0;
        int i1 = (int)numStr1.size() - 1;
        while (i1 >= 0) {
            int num1 = (numStr1[i1] - '0');
            // index from 0 to (size1+size2-2)
            int resultIndex = size1 - i1 - 1 + size2 - i2 - 1;
            int resultNum = (result[resultIndex] - '0');
            // calculate current number
            carryNum = num1 * num2 + carryNum + resultNum;
            // replace index char in result
            result[resultIndex] = ('0' + (carryNum % 10));
            carryNum /= 10;
            i1--;
        }
        // the last carry number
        result[(size1 - i1 - 1 + size2 - i2 - 1)] = '0' + carryNum;
        i2--;
    }
    
    reverse(result.begin(), result.end());
    // find 0 position and remove
    int i = 0;
    while (i < result.size()-1 && result[i] == '0')
        i++;
    result.erase(0, i);
    
    return result;
}
