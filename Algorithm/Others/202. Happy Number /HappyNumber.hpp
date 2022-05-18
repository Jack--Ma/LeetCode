//
//  HappyNumber.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/17.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef HappyNumber_hpp
#define HappyNumber_hpp

#include <stdio.h>

// https://leetcode.com/problems/happy-number/
class Solution_202 {
private:
    unordered_set<int> numSet;
    
public:
    bool isHappy(int n);
};

void testHappyNumber();

#endif /* HappyNumber_hpp */
