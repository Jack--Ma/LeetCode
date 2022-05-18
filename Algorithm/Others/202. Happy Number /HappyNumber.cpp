//
//  HappyNumber.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/17.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "HappyNumber.hpp"

/**
 Write an algorithm to determine if a number n is happy.
 
 A happy number is a number defined by the following process:
    * Starting with any positive integer, replace the number by the sum of the squares of its digits.
    * Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
    * Those numbers for which this process ends in 1 are happy.
 Return true if n is a happy number, and false if not.
 
 Input: n = 19
 Output: true
 Explanation:
 1^2 + 9^2 = 82
 8^2 + 2^2 = 68
 6^2 + 8^2 = 100
 1^2 + 0^2 + 0^2 = 1
 */

void testHappyNumber() {
    cout << Solution_202().isHappy(pow(2, 31) - 1) << endl;
}

bool Solution_202::isHappy(int n) {
    // use a set represents all numbers traversed
    if (numSet.find(n) != numSet.end()) {
        return false;
    }
    numSet.insert(n);
    int nextN = 0;
    while (n > 0) {
        int a = n % 10;
        nextN += pow(a, 2);
        n = n / 10;
    }
    
    if (nextN == 1) {
        return true;
    } else {
        return isHappy(nextN);
    }
}
