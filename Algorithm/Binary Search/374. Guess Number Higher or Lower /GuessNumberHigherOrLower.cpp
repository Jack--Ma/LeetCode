//
//  GuessNumberHigherOrLower.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/21.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "GuessNumberHigherOrLower.hpp"

/**
 We are playing the Guess Game. The game is as follows:
 
 I pick a number from 1 to n. You have to guess which number I picked.
 
 Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.
 
 You call a pre-defined API int guess(int num), which returns three possible results:
    * -1: Your guess is higher than the number I picked (i.e. num > pick).
    * 1: Your guess is lower than the number I picked (i.e. num < pick).
    * 0: your guess is equal to the number I picked (i.e. num == pick).
 Return the number that I picked.
 
 Input: n = 10, pick = 6
 Output: 6
 */

void testGuessNumberHigherOrLower() {
    cout << Solution().guessNumber(10) << endl;
}

int guess(int num) {
    if (num > 6) {
        return -1;
    } else if (num < 6) {
        return 1;
    }
    return 0;
}

int Solution::guessNumber(int n) {
    long left = 1, right = n;
    while (left <= right) {
        int p = int((left+right) / 2);
        if (guess(p) < 0) {
            right = p-1;
        } else if (guess(p) > 0) {
            left = p+1;
        } else {
            return p;
        }
    }
    
    return 0;
}
