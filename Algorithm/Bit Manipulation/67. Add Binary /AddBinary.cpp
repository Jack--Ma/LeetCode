//
//  AddBinary.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/6/6.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "AddBinary.hpp"

/**
 Given two binary strings a and b, return their sum as a binary string.
 
 Input: a = "11", b = "1"
 Output: "100"
 
 Input: a = "1010", b = "1011"
 Output: "10101"
 */

void testAddBinary() {
    cout << Solution().addBinary("1", "11") << endl;
}

string Solution::addBinary(string a, string b) {
    const int l1 = (int)a.length();
    const int l2 = (int)b.length();
    string result;
    int carryFlag = 0;
    int p_a = l1-1, p_b = l2-1;
    while (p_a >= 0 || p_b >= 0) {
        int num_a = p_a >= 0 ? a[p_a--] - '0' : 0;
        int num_b = p_b >= 0 ? b[p_b--] - '0' : 0;
        result.insert(result.begin(), (num_a+num_b+carryFlag) % 2 + '0');
        carryFlag = (num_a+num_b+carryFlag) / 2;
    }
    if (carryFlag == 1) {
        result.insert(result.begin(), '1');
    }
    return result;
}
