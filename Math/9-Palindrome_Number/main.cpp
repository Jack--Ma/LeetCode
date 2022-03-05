//
//  main.cpp
//  9-Palindrome_Number
//
//  Created by JackMa on 2016/9/23.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

bool isPalindrome(int x) {
    if (x < 0) return false;
    //left表示高位，right表示低位
    long n = 0, temp = x, left = 1, right = 1;
    while (temp > 0) {
        n++;
        temp /= 10;
        left *= 10;
    }
    left /= 10;
    for (int i = 0; i < n/2; i++) {
        //对比前后数字
        if ((x/left)%10 != (x/right)%10) {
            return false;
        }
        left /= 10;
        right *= 10;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    cout << isPalindrome(1000000001) << endl;
    return 0;
}
