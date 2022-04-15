//
//  ClimbingStairs.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/15.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "ClimbingStairs.hpp"

/**
 You are climbing a staircase. It takes n steps to reach the top.
 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 
 Input: n = 3
 Output: 3
 Explanation: There are three ways to climb to the top.
 1. 1 step + 1 step + 1 step
 2. 1 step + 2 steps
 3. 2 steps + 1 step
 */

void testClimbingStairs() {
    cout << Solution().climbStairs(45) << endl;
}

/// solution by use recursion
/// @note Time Limit Exceeded
void _climbStairs_recursion(int& result, int n) {
    if (n == 0) {
        result++;
        return;
    } else if (n == 1) {
        _climbStairs_recursion(result, n-1);
    } else {
        _climbStairs_recursion(result, n-1);
        _climbStairs_recursion(result, n-2);
    }
}

int _climbStairs_recursion_DP(int n) {
    /**
     n=1: f(1) = 1
     n=2: f(2) = 2
     n=3: f(3) = f(2)+f(1) = 3
     n=4: f(4) = f(3)+f(2) = 5
     n=5: f(5) = f(4)+f(3) = 8
     */
    
    if (n > 2) {
        return _climbStairs_recursion_DP(n-1) + _climbStairs_recursion_DP(n-2);
    } else if (n == 2) {
        return 2;
    } else {
        return 1;
    }
}

/// solution by use dynamic programming
int Solution::climbStairs(int n) {
    int cache[50];
    cache[1] = 1;
    cache[2] = 2;
    for (int i = 3; i <= n; i++) {
        // f(n) = f(n-1) + f(n-2)
        cache[i] = cache[i-1] + cache[i-2];
    }
    return cache[n];
}
