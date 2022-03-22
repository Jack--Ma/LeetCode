//
//  FindTheWinnerOfTheCircularGame.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/22.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <queue>
#include "FindTheWinnerOfTheCircularGame.hpp"

/**
 There are n friends that are playing a game. The friends are sitting in a circle and are numbered from 1 to n in clockwise order. More formally, moving clockwise from the ith friend brings you to the (i+1)th friend for 1 <= i < n, and moving clockwise from the nth friend brings you to the 1st friend.

 The rules of the game are as follows:
    1. Start at the 1st friend.
    2. Count the next k friends in the clockwise direction including the friend you started at. The counting wraps around the circle and may count some friends more than once.
    3. The last friend you counted leaves the circle and loses the game.
    4. If there is still more than one friend in the circle, go back to step 2 starting from the friend immediately clockwise of the friend who just lost and repeat.
    5. Else, the last friend in the circle wins the game.
 Given the number of friends, n, and an integer k, return the winner of the game.
 
 Input: n = 5, k = 2
 Output: 3
 Explanation: The friends leave in this order: 2, 4, 1, 5. The winner is friend 3.
 
 Input: n = 6, k = 5
 Output: 1
 Explanation: The friends leave in this order: 5, 4, 6, 2, 3. The winner is friend 1.
 
 Constraints: 1 <= k <= n <= 500
 */

void testFindTheWinner() {
    cout << Solution().findTheWinner(5, 2) << endl;
}

// solution by use queue
int _findTheWinner(queue<int> queue, int k) {
    int size = (int)queue.size();
    int _k = k % size != 0 ? k % size : size;
    int i = 1;
    while (i < _k) {
        int front = queue.front();
        queue.pop();
        queue.push(front);
        i++;
    }
    // i == _k
    queue.pop();
    if (queue.size() == 1) {
        return queue.front();
    } else {
        return _findTheWinner(queue, k);
    }
}

// solution by use reverse
int _findThWinner(int n, int k) {
    int result = 0;

    /**
     recursion formula: f(n, k) = (f(n−1, k) + k) % n
     in every loop, the result go forward in k step
     eg n = 5, k = 2
     i = 1: result's index = f(1, 2) = 0    3
     i = 2: result's index = f(2, 2) = 0    3 5
     i = 3: result's index = f(3, 2) = 2    5 1 3
     i = 4: result's index = f(4, 2) = 0    3 4 5 1
     i = 5: result's index = f(5, 2) = 2    1 2 3 4 5
     */
    for (int i = 1; i <= n; i++) {
        result = (result + k) % i;
    }
    return result + 1;
}

int Solution::findTheWinner(int n, int k) {
    return _findThWinner(n, k);
    if (n <= 1) {
        return n;
    }
    queue<int> queue;
    for (int i = 1; i <= n; i++) {
        queue.push(i);
    }
    return _findTheWinner(queue, k);
}
